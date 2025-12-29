#include "framework.hpp"
#include "communication/io.hpp"
#include "util/console.hpp"

void main(HMODULE module) {
	std::unique_ptr<console> module_console = std::make_unique<console>("anticheat");
	if (!module_console->create())
		return;

	std::unique_ptr<anticheat::io> anticheat_interface = std::make_unique<anticheat::io>();
	anticheat_interface->open_device();

	ac_register_process input = {};
	input.process_id = GetCurrentProcessId();

	ac_packet packet = {};
	packet.buffer = &input;
	packet.buffer_size = sizeof(input);
	packet.request_code = ac_packet_request::register_process;

	anticheat_interface->send_irp(&packet);

	printf("(+) hello world \n");

	while (!GetAsyncKeyState(VK_END)) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100)); 
	}

	packet.request_code = ac_packet_request::unregister_process;
	anticheat_interface->send_irp(&packet);

	module_console->destroy();
	FreeLibraryAndExitThread(module, 0);
}

bool DllMain(HMODULE module, uint32_t reason, 
	void* reserved) {
	DisableThreadLibraryCalls(module);

	switch (reason) {
	case DLL_PROCESS_ATTACH: {
		const auto thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, module, 0, 0);
		if (thread)
			CloseHandle(thread);
		break;
	}

	default:
		break;
	}

	return true;
}