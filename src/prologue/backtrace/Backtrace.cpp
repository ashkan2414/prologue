#include "prologue/Backtrace.h"

using namespace prologue;

BacktraceInfo prologue::GetBacktraceInfo(const BacktraceInfoConfig& config, prologue_uint skipFrames, prologue_uint maxFrames)
{
    Backtrace backtrace = GetBacktrace(skipFrames, MAX_ALLOWED_BACKTRACE_FRAMES);
    return GetBacktraceInfo(config, backtrace);
}