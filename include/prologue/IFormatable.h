#pragma once

#include "core/PrologueSTL.h"

namespace prologue
{
    class PROLOGUE_NO_VTABLE IFormatable 
    {
    public:
        virtual String Format() = 0;
        virtual WString FormatW() = 0;
    };
} // namespace prologue
