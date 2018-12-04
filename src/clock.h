
#pragma once

#include <cstdint>
#include "nlohmann/json.hpp"

namespace Time
{
    int64_t GetTick();
    int64_t GetTicksPerSecond();

    double GetTime();
    double GetTimeResolution();

}  // namespace Time
