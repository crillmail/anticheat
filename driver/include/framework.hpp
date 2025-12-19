#ifndef framework_hpp
#define framework_hpp

#include <ntifs.h>
#include <ntddk.h>
#include <cstdint>
#include <ntimage.h>

#include "types/arc.hpp"
#include "types/haltypes.hpp"
#include "types/wdbgexts.hpp"
#include "types/ketypes.hpp"
#include "types/ia32.hpp"

extern "C" const char* PsGetProcessImageFileName(PEPROCESS);

#endif // !framework_hpp