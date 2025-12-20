#include "framework.hpp"
#include "util/console.hpp"

void main(HMODULE module) {
	std::unique_ptr<console> module_console = 
		std::make_unique<console>("anticheat");
	if (!module_console->create())
		return;

	printf("(+) hello world \n");

	while (!GetAsyncKeyState(VK_END)) {}

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