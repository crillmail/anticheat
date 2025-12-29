#ifndef types_hpp
#define types_hpp

#include "framework.hpp"

enum class ac_packet_request : uint32_t {
	null = 0,
	register_process,
	unregister_process
};

typedef struct _ac_packet {
	ac_packet_request request_code;

	void* buffer = nullptr;
	uint64_t buffer_size = 0;

	template <typename T> T* get_input() {
		if (sizeof(T) != buffer_size)
			return nullptr;

		return (T*)buffer;
	}
}ac_packet, *pac_packet;

typedef struct _ac_register_process {
	uint32_t process_id = 0;
}ac_register_process, *pac_register_process;

typedef struct _ac_unregister_process {
	uint32_t process_id = 0;
}ac_unregister_process, * pac_unregister_process;

#endif // !types_hpp