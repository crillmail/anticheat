#ifndef console_hpp
#define console_hpp

#include "framework.hpp"

class console {
public:
	console(std::string title) : m_title(title) {}
	~console() { destroy(); }

	bool create() {
		if (GetConsoleWindow()) {
			ShowWindow(GetConsoleWindow(), SW_SHOW);
			UpdateWindow(GetConsoleWindow());
			return true;
		}

		if (!AllocConsole())
			return false;

		SetWindowTextA(GetConsoleWindow(), m_title.c_str());

		freopen_s(&m_file, "CONOUT$", "w", stdout);
		freopen_s(&m_file, "CONIN$", "r", stdin);

		return true;
	}

	void destroy() {
		if (m_file)
			fclose(m_file);

		const auto console_window = GetConsoleWindow();
		if (console_window) {
			ShowWindow(console_window, SW_HIDE);
			UpdateWindow(console_window);
			FreeConsole();
		}
	}
private:
	std::string m_title;
	FILE* m_file = nullptr;
};


#endif // !console_hpp