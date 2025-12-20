#include "communication/io.hpp"

NTSTATUS anticheat::io::irp_handler(PDEVICE_OBJECT device_object, PIRP irp) {
    auto* isl = irp->Tail.Overlay.CurrentStackLocation;
    if (!isl) {
        irp->IoStatus.Status = STATUS_INVALID_DEVICE_STATE;
        irp->IoStatus.Information = 0;
        IofCompleteRequest(irp, IO_NO_INCREMENT);
        return STATUS_INVALID_DEVICE_STATE;
    }

    auto status = STATUS_SUCCESS;

    irp_io_context irp_context = { device_object, irp, isl };

    switch (isl->MajorFunction) {
    case IRP_MJ_CLOSE:
        break; // no idea what to do with this one. handle to device is getting closed
    case IRP_MJ_CREATE:
        status = create_handler(&irp_context);
        break;
    case IRP_MJ_DEVICE_CONTROL:
        status = device_control_handler(&irp_context);
        break;
    default:
        status = STATUS_NOT_SUPPORTED;
        break;
    }

    // don't wanna set information here let the handler set that...
    irp->IoStatus.Status = status;
    IofCompleteRequest(irp, IO_NO_INCREMENT);
    return status;
}

NTSTATUS anticheat::io::create_handler(pirp_io_context context) {
    // add checking here in the future to restrict access to device
    return STATUS_SUCCESS;
}

NTSTATUS anticheat::io::device_control_handler(pirp_io_context context) {
    return STATUS_SUCCESS;
}