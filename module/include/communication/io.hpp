#ifndef io_hpp
#define io_hpp

#include "framework.hpp"
#include "types.hpp"

namespace anticheat {
	class io {
	public:
		io() = default;
		~io();

		bool open_device();
		bool close_device();

		bool send_irp(pac_packet packet);
	private:
		HANDLE m_device_handle = nullptr;
	};
}

#endif // !io_hpp