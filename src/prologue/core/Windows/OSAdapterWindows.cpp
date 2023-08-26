#pragma once

#include "../Platform.h"
#include <cstdlib>

#if PROLOGUE_WINDOWS

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
        return _aligned_malloc(size, alignment);
    }

    void AlignedFree(void* ptr)
    {
        _aligned_free(ptr);
    }

#endif // PROLOGUE_WINDOWS
