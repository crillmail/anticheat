#include "communication/operations.hpp"

NTSTATUS anticheat::operations::handle_register_process(pac_packet packet) {
    auto* input = packet->get_input<ac_register_process>();
    if (!input)
        return STATUS_INVALID_PARAMETER;


    return STATUS_SUCCESS;
}

NTSTATUS anticheat::operations::handle_unregister_process(pac_packet packet) {
    auto* input = packet->get_input<ac_register_process>();
    if (!input)
        return STATUS_INVALID_PARAMETER;


    return STATUS_SUCCESS;
}