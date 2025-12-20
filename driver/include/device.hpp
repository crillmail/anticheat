#ifndef device_hpp
#define device_hpp

#include "framework.hpp"

namespace anticheat {
    class device {
    public:
       static NTSTATUS create_device(const PDRIVER_OBJECT driver_object, const wchar_t* device_name,
            const wchar_t* symbolic_link,
            const uint32_t device_flags);

       static NTSTATUS destroy_device(const PDRIVER_OBJECT driver_object, const wchar_t* symbolic_link);
    };
}

#endif // !device_hpp