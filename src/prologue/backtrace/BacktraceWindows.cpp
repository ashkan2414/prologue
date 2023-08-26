#include "prologue/Backtrace.h"

using namespace prologue;

#ifdef PROLOGUE_PLATFORM_WINDOWS

Backtrace prologue::GetBacktrace(prologue_uint skipFrames, prologue_uint maxFrames)
{

}

BacktraceInfo prologue::GetBacktraceInfo(const BacktraceInfoConfig& config, const Backtrace& backtrace)
{

}

BacktraceInfo prologue::GetBacktraceInfo(prologue_pid pid, const BacktraceInfoConfig& config, const Backtrace& backtrace)
{

}

#endif // PROLOGUE_PLATFORM_WINDOWS