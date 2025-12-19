#ifndef arc_hpp
#define arc_hpp

#include "framework.hpp"

struct _VIRTUAL_EFI_RUNTIME_SERVICES {
	unsigned __int64 GetTime;
	unsigned __int64 SetTime;
	unsigned __int64 GetWakeupTime;
	unsigned __int64 SetWakeupTime;
	unsigned __int64 SetVirtualAddressMap;
	unsigned __int64 ConvertPointer;
	unsigned __int64 GetVariable;
	unsigned __int64 GetNextVariableName;
	unsigned __int64 SetVariable;
	unsigned __int64 GetNextHighMonotonicCount;
	unsigned __int64 ResetSystem;
	unsigned __int64 UpdateCapsule;
	unsigned __int64 QueryCapsuleCapabilities;
	unsigned __int64 QueryVariableInfo;
};

struct _EFI_FIRMWARE_INFORMATION {
	unsigned int FirmwareVersion;
	_VIRTUAL_EFI_RUNTIME_SERVICES* VirtualEfiRuntimeServices;
	int SetVirtualAddressMapStatus;
	unsigned int MissedMappingsCount;
	_LIST_ENTRY FirmwareResourceList;
	void* EfiMemoryMap;
	unsigned int EfiMemoryMapSize;
	unsigned int EfiMemoryMapDescriptorSize;
};

struct _PCAT_FIRMWARE_INFORMATION {
	unsigned int PlaceHolder;
};

struct _FIRMWARE_INFORMATION_LOADER_BLOCK {
	unsigned __int32 FirmwareTypeUefi : 1;
	unsigned __int32 EfiRuntimeUseIum : 1;
	unsigned __int32 EfiRuntimePageProtectionSupported : 1;
	unsigned __int32 Reserved : 29;

	union {
		_EFI_FIRMWARE_INFORMATION EfiInformation;
		_PCAT_FIRMWARE_INFORMATION PcatInformation;
	}$99A60062AD38D16551832D4FBE51F003;
};

struct _I386_LOADER_BLOCK {
    void* CommonDataArea;
    unsigned int MachineType;
    unsigned int VirtualBias;
};

struct _ARM_LOADER_BLOCK{
    unsigned int PlaceHolder;
};

struct _LOADER_PARAMETER_BLOCK {
	unsigned int OsMajorVersion;
	unsigned int OsMinorVersion;
	unsigned int Size;
	unsigned int OsLoaderSecurityVersion;
	_LIST_ENTRY LoadOrderListHead;
	_LIST_ENTRY MemoryDescriptorListHead;
	_LIST_ENTRY BootDriverListHead;
	_LIST_ENTRY EarlyLaunchListHead;
	_LIST_ENTRY CoreDriverListHead;
	_LIST_ENTRY CoreExtensionsDriverListHead;
	_LIST_ENTRY TpmCoreDriverListHead;
	unsigned __int64 KernelStack;
	struct _KPRCB* Prcb;
	unsigned __int64 Process;
	unsigned __int64 Thread;
	unsigned int KernelStackSize;
	unsigned int RegistryLength;
	void* RegistryBase;
	struct _CONFIGURATION_COMPONENT_DATA* ConfigurationRoot;
	char* ArcBootDeviceName;
	char* ArcHalDeviceName;
	char* NtBootPathName;
	char* NtHalPathName;
	char* LoadOptions;
	struct _NLS_DATA_BLOCK* NlsData;
	struct _ARC_DISK_INFORMATION* ArcDiskInformation;
	struct _LOADER_PARAMETER_EXTENSION* Extension;
	union { 
	    _I386_LOADER_BLOCK I386;
	    _ARM_LOADER_BLOCK Arm;
	}$4E6223E6FB79A7F5777BDBCAFC01C55C;
	_FIRMWARE_INFORMATION_LOADER_BLOCK FirmwareInformation;
	char* OsBootstatPathName;
	char* ArcOSDataDeviceName;
	char* ArcWindowsSysPartName;
};

#endif // !arc_hpp