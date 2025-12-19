#ifndef create_process_hpp
#define create_process_hpp

#include "framework.hpp"

namespace callbacks {
	class create_process {
	public:
		static void routine(PEPROCESS process,
			HANDLE process_id,
			PPS_CREATE_NOTIFY_INFO create_info);
	};
}
#endif // !create_process_hpp