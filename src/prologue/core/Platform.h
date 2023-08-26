#pragma once

#include "Config.h"
#include "Types.h"

namespace Prologue
{
    void* Alloc(prologue_size size);
    void Free(void* ptr);

    void* AlignedAlloc(prologue_size size, prologue_size alignment);
    void AlignedFree(void* ptr);
} // namespace Prologue