#pragma once

#include "PrologueSTL.h"

namespace prologue
{

    #ifdef PROLOGUE_PLATFORM_WINDOWS
    using Path = WString;
    #elif PROLOGUE_PLATFORM_LINUX
    using Path = String;
    #endif
    
} // namespace prologue
