#include "callbacks/create_process.hpp"

void callbacks::create_process::routine(PEPROCESS process, 
	HANDLE process_id, 
	PPS_CREATE_NOTIFY_INFO create_info) {
	const auto process_created = create_info != nullptr;
	if (!process_created)
		return;


}