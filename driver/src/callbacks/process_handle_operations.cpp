#include "callbacks/process_handle_operations.hpp"

OB_PREOP_CALLBACK_STATUS callbacks::process_handle_operations::process_handle_routine(void* registration_context,
	POB_PRE_OPERATION_INFORMATION operation_information) {
	if (IoIsSystemThread(KeGetCurrentThread()) || operation_information->KernelHandle)
		return OB_PREOP_SUCCESS; // system processes

	auto* current_process = IoGetCurrentProcess();
	auto* target_process = (PEPROCESS)operation_information->Object;

	if (current_process == target_process)
		return OB_PREOP_SUCCESS; // process opening handles to its self

	const auto current_process_id = (uint32_t)PsGetCurrentProcessId();
	const auto target_process_id = (uint32_t)PsGetProcessId(target_process);

	if (strcmp(PsGetProcessImageFileName(target_process), "notepad.exe"))
		return OB_PREOP_SUCCESS;

	switch (operation_information->Operation) {
	case OB_OPERATION_HANDLE_CREATE:
		operation_information->Parameters->CreateHandleInformation.DesiredAccess = 0;
		break;
	case OB_OPERATION_HANDLE_DUPLICATE:
		operation_information->Parameters->DuplicateHandleInformation.DesiredAccess = 0;
		break;
	}

	return OB_PREOP_SUCCESS;
}

OB_PREOP_CALLBACK_STATUS callbacks::process_handle_operations::process_thread_handle_routine(void* registration_context, 
	POB_PRE_OPERATION_INFORMATION operation_information) {
	if (IoIsSystemThread(KeGetCurrentThread()) || operation_information->KernelHandle)
		return OB_PREOP_SUCCESS; // system processes

	auto* current_process = IoGetCurrentProcess();
	auto* target_thread = (PETHREAD)operation_information->Object;

	if (current_process == PsGetThreadProcess(target_thread))
		return OB_PREOP_SUCCESS; // process opening handles to its self

	const auto current_process_id = (uint32_t)PsGetCurrentProcessId();
	const auto target_thread_id = (uint32_t)PsGetThreadId(target_thread);

	if (strcmp(PsGetProcessImageFileName(PsGetThreadProcess(target_thread)), "notepad.exe"))
		return OB_PREOP_SUCCESS;

	switch (operation_information->Operation) {
	case OB_OPERATION_HANDLE_CREATE:
		operation_information->Parameters->CreateHandleInformation.DesiredAccess = 0;
		break;
	case OB_OPERATION_HANDLE_DUPLICATE:
		operation_information->Parameters->DuplicateHandleInformation.DesiredAccess = 0;
		break;
	}

	return OB_PREOP_SUCCESS;
}