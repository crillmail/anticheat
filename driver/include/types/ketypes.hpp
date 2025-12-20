#ifndef ketypes_hpp
#define ketypes_hpp

typedef struct _KTHREAD {
    char pad_0_0x90[0x90];
    PKTRAP_FRAME TrapFrame;                      
}KTHREAD, *PKTHREAD;

typedef struct _KPROCESS {
    struct _DISPATCHER_HEADER Header;
    struct _LIST_ENTRY ProfileListHead;
    ULONGLONG DirectoryTableBase;
}KPROCESS, *PKPROCESS;

typedef union _KIDTENTRY64 {
    struct {
        uint16_t OffsetLow;
        uint16_t Selector;
        uint16_t IstIndex : 3;
        uint16_t Reserved0 : 5;
        uint16_t Type : 5;
        uint16_t Dpl : 2;
        uint16_t Present : 1;
        uint16_t OffsetMiddle;
        uint32_t OffsetHigh;
        uint32_t Reserved1;
    };
    uint64_t Alignment;
} KIDTENTRY64, * PKIDTENTRY64;

#endif // !ketypes_hpp