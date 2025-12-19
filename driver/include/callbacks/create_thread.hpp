#ifndef create_thread_hpp
#define create_thread_hpp

#include "framework.hpp"

namespace callbacks {
	class create_thread {
	public:
		static void routine(HANDLE process_id,
			HANDLE thread_id,
			bool create);
	};
}

#endif // !create_thread_hpp