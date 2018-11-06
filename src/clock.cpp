
#include "clock.h"

#include <chrono>

namespace
{
    const auto kNanoSecondsPerSecond = 1000000000;
}

namespace Time
{
    int64_t GetTick()
    {
        auto timestamp   = std::chrono::high_resolution_clock::now().time_since_epoch();
        auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(timestamp).count();

        return nanoseconds;
    }

    int64_t GetTicksPerSecond() { return kNanoSecondsPerSecond; }

    double GetTime() { return (double)GetTick() / GetTicksPerSecond(); }

    double GetTimeResolution() { return 1.0 / GetTicksPerSecond(); }

}  // namespace Time
