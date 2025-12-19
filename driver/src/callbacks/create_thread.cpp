#include "callbacks/create_thread.hpp"

void callbacks::create_thread::routine(HANDLE process_id, HANDLE thread_id,
    bool create) {
    if (!create)
        return;

    const auto thread_process_id = (uint32_t)process_id;
    const auto current_process_id = (uint32_t)PsGetCurrentProcessId(); 
}