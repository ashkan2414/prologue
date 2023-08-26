#pragma once

#include "../Platform.h"

#if PROLOGUE_LINUX

    void* Alloc(prologue_size size)
    {
        return malloc(size);
    }
    
    void Free(void * ptr)
    {
        free(ptr);
    }

    void* AlignedAlloc(prologue_size size, prologue_size alignment)
    {
        
    }

    void AlignedFree(void* ptr)
    {

    }

#endif // PROLOGUE_LINUX