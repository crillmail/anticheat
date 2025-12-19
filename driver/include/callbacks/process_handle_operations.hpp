#ifndef process_handle_operations_hpp
#define process_handle_operations_hpp

#include "framework.hpp"

namespace callbacks {
	class process_handle_operations {
	public:
		static OB_PREOP_CALLBACK_STATUS process_handle_routine(void* registration_context,
			POB_PRE_OPERATION_INFORMATION operation_information);

		static OB_PREOP_CALLBACK_STATUS process_thread_handle_routine(void* registration_context,
			POB_PRE_OPERATION_INFORMATION operation_information);
	};
}

#endif // !process_handle_operations_hpp
