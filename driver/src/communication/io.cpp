#include "communication/io.hpp"

NTSTATUS anticheat::io::irp_handler(PDEVICE_OBJECT device_object, PIRP irp) {
    if (!device_object || !irp)
        return STATUS_INVALID_PARAMETER;

    auto* isl = irp->Tail.Overlay.CurrentStackLocation;
    if (!isl)
        return STATUS_INVALID_PARAMETER_1;

    auto status = STATUS_SUCCESS;

    switch (isl->MajorFunction) {
    case IRP_MJ_CLOSE:
    case IRP_MJ_CREATE:
        status = complete_request(irp, STATUS_SUCCESS, 0);
        break;
    case IRP_MJ_DEVICE_CONTROL:
        status = complete_request(irp, STATUS_SUCCESS, 0);
        break;
    default:
        status = complete_request(irp, STATUS_UNSUCCESSFUL, 0);
        break;
    }

    return status;
}

NTSTATUS anticheat::io::complete_request(PIRP irp, NTSTATUS status, uint32_t information) {
    if (!irp)
        return STATUS_ACCESS_VIOLATION;

    auto* status_block = &irp->IoStatus;
    status_block->Information = information;
    status_block->Status = status;
    IofCompleteRequest(irp, IO_NO_INCREMENT);

    return status;
}