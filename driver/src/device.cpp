#include "device.hpp"

NTSTATUS anticheat::device::create_device(const PDRIVER_OBJECT driver_object,
    const wchar_t* device_name,
    const wchar_t* symbolic_link,
    const uint32_t device_flags) {
    if (!driver_object || !device_name || !symbolic_link)
        return STATUS_INVALID_PARAMETER;

    UNICODE_STRING device_name_string = {}, symbolic_link_string = {};

    RtlInitUnicodeString(&device_name_string, device_name);
    RtlInitUnicodeString(&symbolic_link_string, symbolic_link);

    PDEVICE_OBJECT device_object = nullptr;
    auto status = IoCreateDevice(driver_object,
        0,
        &device_name_string,
        FILE_DEVICE_UNKNOWN,
        device_flags,
        false,
        &device_object);

    if (!NT_SUCCESS(status))
        return status;

    status = IoCreateSymbolicLink(&symbolic_link_string, &device_name_string);
    if (!NT_SUCCESS(status)) {
        IoDeleteDevice(device_object);
        return status;
    }

    return status;
}