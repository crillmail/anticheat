#ifndef image_load_hpp
#define image_load_hpp

#include "framework.hpp"

namespace callbacks {
	class image_load {
	public:
		static void routine(PUNICODE_STRING full_image_name,
			HANDLE process_id,
			PIMAGE_INFO image_info);
	};
}

#endif // !image_load_hpp