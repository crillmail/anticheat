#include "framework.hpp"
#include "device.hpp"
#include "communication/io.hpp"
#include "callbacks/callbacks.hpp"

constexpr wchar_t* device_name = L"\\Device\\anticheat";
constexpr wchar_t* symbolic_name = L"\\??\\anticheat";

void FxDriverUnload(PDRIVER_OBJECT driver_object) {
	anticheat::callback::remove_callbacks();

	auto status = anticheat::device::destroy_device(driver_object, symbolic_name);

	DbgPrint("(+) deleted device -> 0x%lx", status);
}

NTSTATUS FxDriverEntry(PDRIVER_OBJECT driver_object, PUNICODE_STRING registry_path) {
	auto status = anticheat::callback::register_callbacks();
	if (!NT_SUCCESS(status)) {
		DbgPrint("(-) failed to register callbacks -> 0x%lx", status);
		anticheat::callback::remove_callbacks();
		return status;
	}

	status = anticheat::device::create_device(driver_object,
		device_name,
		symbolic_name,
		FILE_DEVICE_SECURE_OPEN);

	if (!NT_SUCCESS(status)) {
		DbgPrint("(-) failed to setup device -> 0x%lx", status);
		anticheat::callback::remove_callbacks();
		return status;
	}

	driver_object->DriverUnload = FxDriverUnload;
	driver_object->MajorFunction[IRP_MJ_CLOSE] = &anticheat::io::irp_handler;
	driver_object->MajorFunction[IRP_MJ_CREATE] = &anticheat::io::irp_handler;
	driver_object->MajorFunction[IRP_MJ_DEVICE_CONTROL] = &anticheat::io::irp_handler;

	DbgPrint("(+) setup device -> 0x%lx", status);

	return STATUS_SUCCESS;
}