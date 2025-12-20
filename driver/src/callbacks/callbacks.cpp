#include "callbacks/callbacks.hpp"

NTSTATUS anticheat::callback::register_callbacks() {
    // linker requires /INTEGRITYCHECK or this fails
    auto status = PsSetCreateProcessNotifyRoutineEx(callbacks::create_process::routine, false);
    if (!NT_SUCCESS(status))
        return status;

    status = PsSetCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)callbacks::create_thread::routine);
    if (!NT_SUCCESS(status)) {
        remove_callbacks();
        return status;
    }

    status = PsSetLoadImageNotifyRoutine((PLOAD_IMAGE_NOTIFY_ROUTINE)callbacks::image_load::routine);
    if (!NT_SUCCESS(status)) {
        remove_callbacks();
        return status;
    }

    OB_OPERATION_REGISTRATION operation_registration[2] = {};
    operation_registration[0].ObjectType = PsProcessType;
    operation_registration[0].Operations = OB_OPERATION_HANDLE_CREATE | OB_OPERATION_HANDLE_DUPLICATE;
    operation_registration[0].PreOperation = &callbacks::process_handle_operations::process_handle_routine;

    operation_registration[1].ObjectType = PsThreadType;
    operation_registration[1].Operations = OB_OPERATION_HANDLE_CREATE | OB_OPERATION_HANDLE_DUPLICATE;
    operation_registration[1].PreOperation = &callbacks::process_handle_operations::process_thread_handle_routine;

    OB_CALLBACK_REGISTRATION callback_registration = {};
    callback_registration.Version = ObGetFilterVersion();
    callback_registration.Altitude = RTL_CONSTANT_STRING(L"385");
    callback_registration.OperationRegistrationCount = sizeof(operation_registration) / sizeof(operation_registration[0]);
    callback_registration.OperationRegistration = operation_registration;

    status = ObRegisterCallbacks(&callback_registration, &process_callback_registration_handle);
    if (!NT_SUCCESS(status)) {
        remove_callbacks();
        return status;
    }

    return status;
}

void anticheat::callback::remove_callbacks() {
    PsSetCreateProcessNotifyRoutineEx(callbacks::create_process::routine, true);
    PsRemoveLoadImageNotifyRoutine((PLOAD_IMAGE_NOTIFY_ROUTINE)callbacks::image_load::routine);
    PsRemoveCreateThreadNotifyRoutine((PCREATE_THREAD_NOTIFY_ROUTINE)callbacks::create_thread::routine);

    if (process_callback_registration_handle)
        ObUnRegisterCallbacks(process_callback_registration_handle);
}