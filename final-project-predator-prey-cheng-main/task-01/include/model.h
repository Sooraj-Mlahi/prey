#pragma once

#include <filesystem>
#include <random>
#include <string>
#include <vector>
#include <numbers>
#include <iostream>

#include <nlohmann/json.hpp>

#include "prey.h"
#include "predator.h"
#include "environment.h"
// #include "food.h"

using json = nlohmann::json;

struct Model
{
    Model(const std::string &configuration_file);

    void update(const double time_delta);

    void finalize();

    json configuration{};
    Predator predator{};
    std::vector<Prey> preys{};
    Environment environment{};
    double time{};
    bool simulation_complete = false;

    std::mt19937 eng{1337};
};