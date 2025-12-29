#include "communication/io.hpp"

anticheat::io::~io() {
    close_device();
}

bool anticheat::io::open_device() {
    m_device_handle = CreateFileA("\\\\.\\anticheat", GENERIC_WRITE | GENERIC_READ, 
        0,
        0,
        OPEN_EXISTING,
        FILE_FLAG_OVERLAPPED,
        0);

    return m_device_handle != INVALID_HANDLE_VALUE;
}

bool anticheat::io::close_device() {
    return CloseHandle(m_device_handle);
}

bool anticheat::io::send_irp(pac_packet packet) {
    return DeviceIoControl(m_device_handle, 0, 
        packet, 
        sizeof(ac_packet),
        packet,
        sizeof(ac_packet),
        nullptr,
        nullptr);
}