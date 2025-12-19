#include "framework.hpp"
#include "device.hpp"
#include "callbacks/callbacks.hpp"

const wchar_t* device_name = L"\\Device\\anticheat";
const wchar_t* symbolic_name = L"\\??\\anticheat";

void FxDriverUnload(PDRIVER_OBJECT driver_object) {
	if (driver_object->DeviceObject) {
		UNICODE_STRING symbolic_name_string = {};
		RtlInitUnicodeString(&symbolic_name_string, symbolic_name);
		auto status = IoDeleteSymbolicLink(&symbolic_name_string);
		IoDeleteDevice(driver_object->DeviceObject);

		DbgPrint("(+) deleted device -> 0x%lx", status);
	}

	rootkit::callback::remove_callbacks();
}

NTSTATUS FxDriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path) {
	auto status = rootkit::device::create_device(driver_object,
		device_name,
		symbolic_name,
		FILE_DEVICE_SECURE_OPEN);

	if (!NT_SUCCESS(status)) {
		DbgPrint("(-) failed to setup device -> 0x%lx", status);
		return status;
	}

	driver_object->DriverUnload = FxDriverUnload;

	DbgPrint("(+) setup device -> 0x%lx", status);
	rootkit::callback::register_callbacks();

	return STATUS_SUCCESS;
}