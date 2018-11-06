
#pragma once

template<typename... T> void UNUSED_ARGS(T&&...) {}  // NOLINT(readability-named-parameter)

#pragma warning(push)
#pragma warning(disable : 4127)
#include "fmt/format.h"  // NOLINT
#pragma warning(pop)

#if _DEBUG
namespace Debug
{
    template<typename... T> void Assert(bool condition, const char* str_condition, const char* format, T&&... args)
    {
        if (!condition)
        {
            auto message = fmt::format(format, std::forward<T>(args)...);
            fmt::print("Assertion: {} - {}\n", str_condition, message);
        }
    }

#define Assert(condition, message, ...)                               \
    if (!(condition))                                                 \
    {                                                                 \
        static bool _local_enabled = true;                            \
        Debug::Assert((condition), #condition, message, __VA_ARGS__); \
        if (_local_enabled) { __debugbreak(); }                       \
    }
}  // namespace Debug
#else
#define Assert(...)
#endif

template<typename... T> void Message(T&&... args)
{
    fmt::print(
        std::forward<T>(args)...);  // NOLINT(cppcoreguidelines-pro-bounds-array-to-pointer-decay, hicpp-no-array-decay)
}
