#ifndef haltypes_hpp
#define haltypes_hpp

#include "framework.hpp"

typedef struct _HAL_PRIVATE_DISPATCH {
    uint32_t Version;
    struct _BUS_HANDLER* (*HalHandlerForBus)(enum _INTERFACE_TYPE arg1, uint32_t arg2); //0x8
    struct _BUS_HANDLER* (*HalHandlerForConfigSpace)(enum _BUS_DATA_TYPE arg1, uint32_t arg2); //0x10
    void(*HalLocateHiberRanges)(void* arg1);                               //0x18
    int32_t(*HalRegisterBusHandler)(enum _INTERFACE_TYPE arg1, enum _BUS_DATA_TYPE arg2, uint32_t arg3, enum _INTERFACE_TYPE arg4, uint32_t arg5, uint32_t arg6, int32_t(*arg7)(struct _BUS_HANDLER* arg1), struct _BUS_HANDLER** arg8); //0x20
    void(*HalSetWakeEnable)(uint8_t arg1);                                   //0x28
    int32_t(*HalSetWakeAlarm)(uint64_t arg1, uint64_t arg2);                //0x30
    uint8_t(*HalPciTranslateBusAddress)(enum _INTERFACE_TYPE arg1, uint32_t arg2, union _LARGE_INTEGER arg3, uint32_t* arg4, union _LARGE_INTEGER* arg5); //0x38
    int32_t(*HalPciAssignSlotResources)(struct _UNICODE_STRING* arg1, struct _UNICODE_STRING* arg2, struct _DRIVER_OBJECT* arg3, struct _DEVICE_OBJECT* arg4, enum _INTERFACE_TYPE arg5, uint32_t arg6, uint32_t arg7, struct _CM_RESOURCE_LIST** arg8); //0x40
    void(*HalHaltSystem)();                                                //0x48
    uint8_t(*HalFindBusAddressTranslation)(union _LARGE_INTEGER arg1, uint32_t* arg2, union _LARGE_INTEGER* arg3, uint64_t* arg4, uint8_t arg5); //0x50
    uint8_t(*HalResetDisplay)();                                             //0x58
    int32_t(*HalAllocateMapRegisters)(struct _ADAPTER_OBJECT* arg1, uint32_t arg2, uint32_t arg3, struct _MAP_REGISTER_ENTRY* arg4); //0x60
    int32_t(*KdSetupPciDeviceForDebugging)(void* arg1, struct _DEBUG_DEVICE_DESCRIPTOR* arg2); //0x68
    int32_t(*KdReleasePciDeviceForDebugging)(struct _DEBUG_DEVICE_DESCRIPTOR* arg1); //0x70
    void* (*KdGetAcpiTablePhase0)(struct _LOADER_PARAMETER_BLOCK* arg1, uint32_t arg2); //0x78
    void(*KdCheckPowerButton)();                                           //0x80
    uint8_t(*HalVectorToIDTEntry)(uint32_t arg1);                               //0x88
    void* (*KdMapPhysicalMemory64)(union _LARGE_INTEGER arg1, uint32_t arg2, uint8_t arg3); //0x90
    void(*KdUnmapVirtualAddress)(void* arg1, uint32_t arg2, uint8_t arg3);      //0x98
    uint32_t(*KdGetPciDataByOffset)(uint32_t arg1, uint32_t arg2, void* arg3, uint32_t arg4, uint32_t arg5); //0xa0
    uint32_t(*KdSetPciDataByOffset)(uint32_t arg1, uint32_t arg2, void* arg3, uint32_t arg4, uint32_t arg5); //0xa8
    uint32_t(*HalGetInterruptVectorOverride)(enum _INTERFACE_TYPE arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint8_t* arg5, uint64_t* arg6); //0xb0
    int32_t(*HalGetVectorInputOverride)(uint32_t arg1, struct _GROUP_AFFINITY* arg2, uint32_t* arg3, enum _KINTERRUPT_POLARITY* arg4, struct _INTERRUPT_REMAPPING_INFO* arg5); //0xb8
    int32_t(*HalLoadMicrocode)(void* arg1);                                   //0xc0
    int32_t(*HalUnloadMicrocode)();                                           //0xc8
    int32_t(*HalPostMicrocodeUpdate)();                                       //0xd0
    int32_t(*HalAllocateMessageTargetOverride)(struct _DEVICE_OBJECT* arg1, struct _GROUP_AFFINITY* arg2, uint32_t arg3, enum _KINTERRUPT_MODE arg4, uint8_t arg5, uint32_t* arg6, uint8_t* arg7, uint32_t* arg8); //0xd8
    void(*HalFreeMessageTargetOverride)(struct _DEVICE_OBJECT* arg1, uint32_t arg2, struct _GROUP_AFFINITY* arg3); //0xe0
    int32_t(*HalDpReplaceBegin)(struct _HAL_DP_REPLACE_PARAMETERS* arg1, void** arg2); //0xe8
    void(*HalDpReplaceTarget)(void* arg1);                                 //0xf0
    int32_t(*HalDpReplaceControl)(uint32_t arg1, void* arg2);                    //0xf8
    void(*HalDpReplaceEnd)(void* arg1);                                    //0x100
    void(*HalPrepareForBugcheck)(uint32_t arg1);                              //0x108
    uint8_t(*HalQueryWakeTime)(uint64_t* arg1, uint64_t* arg2);            //0x110
    void(*HalReportIdleStateUsage)(uint8_t arg1, struct _KAFFINITY_EX* arg2); //0x118
    void(*HalTscSynchronization)(uint8_t arg1, uint32_t* arg2);                 //0x120
    int32_t(*HalWheaInitProcessorGenericSection)(struct _WHEA_ERROR_RECORD_SECTION_DESCRIPTOR* arg1, struct _WHEA_PROCESSOR_GENERIC_ERROR_SECTION* arg2); //0x128
    void(*HalStopLegacyUsbInterrupts)(enum _SYSTEM_POWER_STATE arg1);      //0x130
    int32_t(*HalReadWheaPhysicalMemory)(union _LARGE_INTEGER arg1, uint32_t arg2, void* arg3); //0x138
    int32_t(*HalWriteWheaPhysicalMemory)(union _LARGE_INTEGER arg1, uint32_t arg2, void* arg3); //0x140
    int32_t(*HalDpMaskLevelTriggeredInterrupts)();                            //0x148
    int32_t(*HalDpUnmaskLevelTriggeredInterrupts)();                          //0x150
    int32_t(*HalDpGetInterruptReplayState)(void* arg1, void** arg2);          //0x158
    int32_t(*HalDpReplayInterrupts)(void* arg1);                              //0x160
    uint8_t(*HalQueryIoPortAccessSupported)();                               //0x168
    int32_t(*KdSetupIntegratedDeviceForDebugging)(void* arg1, struct _DEBUG_DEVICE_DESCRIPTOR* arg2); //0x170
    int32_t(*KdReleaseIntegratedDeviceForDebugging)(struct _DEBUG_DEVICE_DESCRIPTOR* arg1); //0x178
    void(*HalGetEnlightenmentInformation)(struct _HAL_INTEL_ENLIGHTENMENT_INFORMATION* arg1); //0x180
    void* (*HalAllocateEarlyPages)(struct _LOADER_PARAMETER_BLOCK* arg1, uint32_t arg2, uint64_t* arg3, uint32_t arg4); //0x188
    void* (*HalMapEarlyPages)(uint64_t arg1, uint32_t arg2, uint32_t arg3);      //0x190
    void* Dummy1;                                                           //0x198
    void* Dummy2;                                                           //0x1a0
    void(*HalNotifyProcessorFreeze)(uint8_t arg1, uint8_t arg2);               //0x1a8
    int32_t(*HalPrepareProcessorForIdle)(uint32_t arg1);                         //0x1b0
    void(*HalRegisterLogRoutine)(struct _HAL_LOG_REGISTER_CONTEXT* arg1);  //0x1b8
    void(*HalResumeProcessorFromIdle)();                                   //0x1c0
    void* Dummy;                                                            //0x1c8
    uint32_t(*HalVectorToIDTEntryEx)(uint32_t arg1);                             //0x1d0
    int32_t(*HalSecondaryInterruptQueryPrimaryInformation)(struct _INTERRUPT_VECTOR_DATA* arg1, uint32_t* arg2); //0x1d8
    int32_t(*HalMaskInterrupt)(uint32_t arg1, uint32_t arg2);                       //0x1e0
    int32_t(*HalUnmaskInterrupt)(uint32_t arg1, uint32_t arg2);                     //0x1e8
    uint8_t(*HalIsInterruptTypeSecondary)(uint32_t arg1, uint32_t arg2);           //0x1f0
    int32_t(*HalAllocateGsivForSecondaryInterrupt)(CHAR* arg1, USHORT arg2, uint32_t* arg3); //0x1f8
    int32_t(*HalAddInterruptRemapping)(uint32_t arg1, uint32_t arg2, struct _PCI_BUSMASTER_DESCRIPTOR* arg3, uint8_t arg4, struct _INTERRUPT_VECTOR_DATA* arg5, uint32_t arg6); //0x200
    void(*HalRemoveInterruptRemapping)(uint32_t arg1, uint32_t arg2, struct _PCI_BUSMASTER_DESCRIPTOR* arg3, uint8_t arg4, struct _INTERRUPT_VECTOR_DATA* arg5, uint32_t arg6); //0x208
    void(*HalSaveAndDisableHvEnlightenment)();                             //0x210
    void(*HalRestoreHvEnlightenment)();                                    //0x218
    void(*HalFlushIoBuffersExternalCache)(struct _MDL* arg1, uint8_t arg2);  //0x220
    void(*HalFlushExternalCache)(uint8_t arg1);                              //0x228
    int32_t(*HalPciEarlyRestore)(enum _SYSTEM_POWER_STATE arg1);              //0x230
    int32_t(*HalGetProcessorId)(uint32_t arg1, uint32_t* arg2, uint32_t* arg3);        //0x238
    int32_t(*HalAllocatePmcCounterSet)(uint32_t arg1, enum _KPROFILE_SOURCE* arg2, uint32_t arg3, struct _HAL_PMC_COUNTERS** arg4); //0x240
    void(*HalCollectPmcCounters)(struct _HAL_PMC_COUNTERS* arg1, uint64_t* arg2); //0x248
    void(*HalFreePmcCounterSet)(struct _HAL_PMC_COUNTERS* arg1);           //0x250
    int32_t(*HalProcessorHalt)(uint32_t arg1, void* arg2, int32_t(*arg3)(void* arg1)); //0x258
    uint64_t(*HalTimerQueryCycleCounter)(uint64_t* arg1);                //0x260
    void* Dummy3;                                                           //0x268
    void(*HalPciMarkHiberPhase)();                                         //0x270
    int32_t(*HalQueryProcessorRestartEntryPoint)(union _LARGE_INTEGER* arg1); //0x278
    int32_t(*HalRequestInterrupt)(uint32_t arg1);                                //0x280
    int32_t(*HalEnumerateUnmaskedInterrupts)(uint8_t(*arg1)(void* arg1, struct _HAL_UNMASKED_INTERRUPT_INFORMATION* arg2), void* arg2, struct _HAL_UNMASKED_INTERRUPT_INFORMATION* arg3); //0x288
    void(*HalFlushAndInvalidatePageExternalCache)(union _LARGE_INTEGER arg1); //0x290
    int32_t(*KdEnumerateDebuggingDevices)(void* arg1, struct _DEBUG_DEVICE_DESCRIPTOR* arg2, enum KD_CALLBACK_ACTION(*arg3)(struct _DEBUG_DEVICE_DESCRIPTOR* arg1)); //0x298
    void(*HalFlushIoRectangleExternalCache)(struct _MDL* arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, uint32_t arg5, uint8_t arg6); //0x2a0
    void(*HalPowerEarlyRestore)(uint32_t arg1);                               //0x2a8
    int32_t(*HalQueryCapsuleCapabilities)(void* arg1, uint32_t arg2, uint64_t* arg3, uint32_t* arg4); //0x2b0
    int32_t(*HalUpdateCapsule)(void* arg1, uint32_t arg2, union _LARGE_INTEGER arg3); //0x2b8
    uint8_t(*HalPciMultiStageResumeCapable)();                               //0x2c0
    void(*HalDmaFreeCrashDumpRegisters)(uint32_t arg1);                       //0x2c8
    uint8_t(*HalAcpiAoacCapable)();                                          //0x2d0
    int32_t(*HalInterruptSetDestination)(struct _INTERRUPT_VECTOR_DATA* arg1, struct _GROUP_AFFINITY* arg2, uint32_t* arg3); //0x2d8
    void(*HalGetClockConfiguration)(struct _HAL_CLOCK_TIMER_CONFIGURATION* arg1); //0x2e0
    void(*HalClockTimerActivate)(uint8_t arg1);                              //0x2e8
    void(*HalClockTimerInitialize)();                                      //0x2f0
    void(*HalClockTimerStop)();                                            //0x2f8
    int32_t(*HalClockTimerArm)(enum _HAL_CLOCK_TIMER_MODE arg1, uint64_t arg2, uint64_t* arg3); //0x300
    uint8_t(*HalTimerOnlyClockInterruptPending)();                           //0x308
    void* (*HalAcpiGetMultiNode)();                                         //0x310
    void* dummy5;
    void(*HalIommuRegisterDispatchTable)(struct _HAL_IOMMU_DISPATCH* arg1); //0x320
    void(*HalTimerWatchdogStart)();                                        //0x328
    void(*HalTimerWatchdogResetCountdown)();                               //0x330
    void(*HalTimerWatchdogStop)();                                         //0x338
    uint8_t(*HalTimerWatchdogGeneratedLastReset)();                          //0x340
    int32_t(*HalTimerWatchdogTriggerSystemReset)(uint8_t arg1);                 //0x348
    int32_t(*HalInterruptVectorDataToGsiv)(struct _INTERRUPT_VECTOR_DATA* arg1, uint32_t* arg2); //0x350
    int32_t(*HalInterruptGetHighestPriorityInterrupt)(uint32_t* arg1, uint8_t* arg2); //0x358
    int32_t(*HalProcessorOn)(uint32_t arg1);                                     //0x360
    int32_t(*HalProcessorOff)();                                              //0x368
    int32_t(*HalProcessorFreeze)();                                           //0x370
    int32_t(*HalDmaLinkDeviceObjectByToken)(uint64_t arg1, struct _DEVICE_OBJECT* arg2); //0x378
    int32_t(*HalDmaCheckAdapterToken)(uint64_t arg1);                        //0x380
    void* Dummy4;                                                           //0x388
    int32_t(*HalTimerConvertPerformanceCounterToAuxiliaryCounter)(uint64_t arg1, uint64_t* arg2, uint64_t* arg3); //0x390
    int32_t(*HalTimerConvertAuxiliaryCounterToPerformanceCounter)(uint64_t arg1, uint64_t* arg2, uint64_t* arg3); //0x398
    int32_t(*HalTimerQueryAuxiliaryCounterFrequency)(uint64_t* arg1);        //0x3a0
    int32_t(*HalConnectThermalInterrupt)(uint8_t(*arg1)(struct _KINTERRUPT* arg1, void* arg2)); //0x3a8
    uint8_t(*HalIsEFIRuntimeActive)();                                       //0x3b0
    uint8_t(*HalTimerQueryAndResetRtcErrors)(uint8_t arg1);                    //0x3b8
    void(*HalAcpiLateRestore)();                                           //0x3c0
    int32_t(*KdWatchdogDelayExpiration)(uint64_t* arg1);                     //0x3c8
    int32_t(*HalGetProcessorStats)(enum _HAL_PROCESSOR_STAT_TYPE arg1, uint32_t arg2, uint32_t arg3, uint64_t* arg4); //0x3d0
    uint64_t(*HalTimerWatchdogQueryDueTime)(uint8_t arg1);                  //0x3d8
    int32_t(*HalConnectSyntheticInterrupt)(uint8_t(*arg1)(struct _KINTERRUPT* arg1, void* arg2)); //0x3e0
    void(*HalPreprocessNmi)(uint32_t arg1);                                   //0x3e8
    int32_t(*HalEnumerateEnvironmentVariablesWithFilter)(uint32_t arg1, uint8_t(*arg2)(struct _GUID* arg1, WCHAR* arg2), void* arg3, uint32_t* arg4); //0x3f0
    int32_t(*HalCaptureLastBranchRecordStack)(uint32_t arg1, struct _HAL_LBR_ENTRY* arg2, uint32_t* arg3); //0x3f8
    uint8_t(*HalClearLastBranchRecordStack)();                               //0x400
    int32_t(*HalConfigureLastBranchRecord)(uint32_t arg1, uint32_t arg2);           //0x408
    uint8_t(*HalGetLastBranchInformation)(uint32_t* arg1, uint32_t* arg2);         //0x410
    void(*HalResumeLastBranchRecord)(uint8_t arg1);                          //0x418
    int32_t(*HalStartLastBranchRecord)(uint32_t arg1, uint32_t* arg2);              //0x420
    int32_t(*HalStopLastBranchRecord)(uint32_t arg1);                            //0x428
    int32_t(*HalIommuBlockDevice)(void* arg1);                                //0x430
    int32_t(*HalIommuUnblockDevice)(struct _EXT_IOMMU_DEVICE_ID* arg1, void** arg2); //0x438
    int32_t(*HalGetIommuInterface)(uint32_t arg1, struct _DMA_IOMMU_INTERFACE* arg2); //0x440
    int32_t(*HalRequestGenericErrorRecovery)(void* arg1, uint32_t* arg2);        //0x448
    int32_t(*HalTimerQueryHostPerformanceCounter)(uint64_t* arg1);           //0x450
    int32_t(*HalTopologyQueryProcessorRelationships)(uint32_t arg1, uint32_t arg2, uint8_t* arg3, uint8_t* arg4, uint8_t* arg5, uint32_t* arg6, uint32_t* arg7); //0x458
    void(*HalInitPlatformDebugTriggers)();                                 //0x460
    void(*HalRunPlatformDebugTriggers)(uint8_t arg1);                        //0x468
    void* (*HalTimerGetReferencePage)();                                    //0x470
    int32_t(*HalGetHiddenProcessorPowerInterface)(struct _HIDDEN_PROCESSOR_POWER_INTERFACE* arg1); //0x478
    uint32_t(*HalGetHiddenProcessorPackageId)(uint32_t arg1);                    //0x480
    uint32_t(*HalGetHiddenPackageProcessorCount)(uint32_t arg1);                 //0x488
    int32_t(*HalGetHiddenProcessorApicIdByIndex)(uint32_t arg1, uint32_t* arg2);    //0x490
    int32_t(*HalRegisterHiddenProcessorIdleState)(uint32_t arg1, uint64_t arg2); //0x498
    void(*HalIommuReportIommuFault)(uint64_t arg1, struct _FAULT_INFORMATION* arg2); //0x4a0
    uint8_t(*HalIommuDmaRemappingCapable)(struct _EXT_IOMMU_DEVICE_ID* arg1, uint32_t* arg2); //0x4a8
} HAL_PRIVATE_DISPATCH, * PHAL_PRIVATE_DISPATCH;


#endif // !haltypes_hpp