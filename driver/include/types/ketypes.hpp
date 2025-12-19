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

#endif // !ketypes_hpp