#ifndef operations_hpp
#define operations_hpp

#include "framework.hpp"
#include "types.hpp"

namespace anticheat {
	class operations {
	public:
		static NTSTATUS handle_register_process(pac_packet packet);

		static NTSTATUS handle_unregister_process(pac_packet packet);
	};
}

#endif // !operations_hpp