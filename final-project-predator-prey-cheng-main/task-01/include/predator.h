#pragma once

#include <array>
#include <vector>
// #include "food.h"
#include "environment.h"

struct Predator
{
    auto update(const double time_delta, const Environment& environment) -> void;

    auto log(const double time) -> void;

    std::array<double, 2> position{};
    std::array<double, 2> velocity{};
};