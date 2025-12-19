#ifndef callbacks_hpp
#define callbacks_hpp

#include "framework.hpp"
#include "create_process.hpp"
#include "create_thread.hpp"
#include "image_load.hpp"
#include "process_handle_operations.hpp"

namespace rootkit {
	class callback {
	public:
		static NTSTATUS register_callbacks();
		static void remove_callbacks();
	private:
		static inline void* process_callback_registration_handle = nullptr;
	};
}

#endif // !callbacks_hpp