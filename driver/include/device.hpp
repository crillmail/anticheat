#ifndef device_hpp
#define device_hpp

#include "framework.hpp"

namespace rootkit {
    class device {
    public:
       static NTSTATUS create_device(const PDRIVER_OBJECT driver_object,
            const wchar_t* device_name,
            const wchar_t* symbolic_link,
            const uint32_t device_flags);
    };
} // namespace rootkit

#endif // !device_hpp