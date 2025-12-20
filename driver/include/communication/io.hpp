#ifndef io_hpp
#define io_hpp

#include "framework.hpp"

namespace anticheat {
	class io {
	public:
		static NTSTATUS irp_handler(PDEVICE_OBJECT device_object, PIRP irp);
	private:
		static NTSTATUS complete_request(PIRP irp, NTSTATUS status, uint32_t information);
	};
}

#endif // !io_hpp