#pragma once

#include "prologue/core/File.h"

namespace prologue
{
    using stack_addr = prologue_uintptr;

#ifdef PROLOGUE_PLATFORM_WINDOWS
    using SymbolName = WString;
#else
    using SymbolName = String;
#endif
    using Backtrace = Vector<stack_addr>;

    struct BacktraceEntry
    {
        prologue_uint       frameNumber; 
        stack_addr          pAddr;

        Path                objectPath;
        SymbolName          symbolName;
        SymbolName          srcSymbolName; // For inlined functions

        Path                srcPath;
        prologue_uint       lineNumber;
        prologue_uint       colNumber;
        String              snippet;             
    };

    using BacktraceInfo = Vector<BacktraceEntry>;
    using BacktraceLine = SymbolName;

    constexpr prologue_uint MAX_ALLOWED_BACKTRACE_FRAMES = 10000;
    constexpr prologue_uint DEFAULT_BACKTRACE_SKIP_FRAMES = 3;
    constexpr prologue_uint NO_BACKTRACE_SNIPPETS = 0;

    struct BacktraceInfoConfig
    {
        prologue_bool demangleSymbols;  // Whether to demangle symbols
        prologue_bool getInline;        // Whether to get symbol name for inlined functions
        prologue_uint snippetLines;     // 0 for no source lines
    };

    Backtrace       GetBacktrace(prologue_uint skipFrames=DEFAULT_BACKTRACE_SKIP_FRAMES, prologue_uint maxFrames=MAX_ALLOWED_BACKTRACE_FRAMES);

    BacktraceInfo   GetBacktraceInfo(const BacktraceInfoConfig& config, const Backtrace& backtrace);
    BacktraceInfo   GetBacktraceInfo(const BacktraceInfoConfig& config, prologue_uint skipFrames=DEFAULT_BACKTRACE_SKIP_FRAMES, prologue_uint maxFrames=MAX_ALLOWED_BACKTRACE_FRAMES);

    BacktraceInfo   GetBacktraceInfo(prologue_pid pid, const BacktraceInfoConfig& config, const Backtrace& backtrace);

} // namespace prologue


