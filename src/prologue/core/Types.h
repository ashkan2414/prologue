#pragma once

#include <cstdint>

// Core

using prologue_bool = bool;

using prologue_char = char;
using prologue_uchar = unsigned char;

using prologue_wchar = wchar_t;

using prologue_short = short;
using prologue_ushort = unsigned short;

using prologue_int = int;
using prologue_uint = unsigned int;

using prologue_long = long;
using prologue_ulong = unsigned long;

using prologue_longlong = long long;
using prologue_ulonglong = unsigned long long;

using prologue_int8 = int8_t;
using prologue_uint8 = uint8_t;

using prologue_int16 = int16_t;
using prologue_uint16 = uint16_t;

using prologue_int32 = int32_t;
using prologue_uint32 = uint32_t;

using prologue_int64 = int64_t;
using prologue_uint64 = uint64_t;

using prologue_intmax = intmax_t; 
using prologue_uintmax = uintmax_t;

using prologue_uintptr = uintptr_t;
using prologue_size = size_t;

using prologue_float = float;
using prologue_double = double;
using prologue_longdouble = long double;

// Platform specific

#ifdef PROLOGUE_PLATFORM_WINDOWS
#include "wtypes.h"
#endif

// PID
#ifdef PROLOGUE_PLATFORM_WINDOWS
using prologue_pid = DWORD;
#else
using prologue_pid = int;
#endif
