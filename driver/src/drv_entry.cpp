#include "framework.hpp"
#include "device.hpp"
#include "callbacks/callbacks.hpp"

const wchar_t* device_name = L"\\Device\\anticheat";
const wchar_t* symbolic_name = L"\\??\\anticheat";

void FxDriverUnload(PDRIVER_OBJECT driver_object) {
	DbgPrint("(+) deleted device -> 0x%lx", 
		anticheat::device::destroy_device(driver_object, symbolic_name));

	anticheat::callback::remove_callbacks();
}

NTSTATUS FxDriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path) {
	auto status = anticheat::device::create_device(driver_object,
		device_name,
		symbolic_name,
		FILE_DEVICE_SECURE_OPEN);

	if (!NT_SUCCESS(status)) {
		DbgPrint("(-) failed to setup device -> 0x%lx", status);
		return status;
	}

	driver_object->DriverUnload = FxDriverUnload;

	DbgPrint("(+) setup device -> 0x%lx", status);

	anticheat::callback::register_callbacks();

	return STATUS_SUCCESS;
}