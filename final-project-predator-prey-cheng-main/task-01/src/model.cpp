#include "model.h"

#include <algorithm>
#include <fstream>
#include <numbers>

using namespace std::numbers;

Model::Model(const std::string& configuration_file)
{
    auto cfs = std::ifstream{ configuration_file };
    configuration = json::parse(cfs);

    auto number_of_preys = configuration["number_of_preys"].get<std::size_t>();
    preys.resize(number_of_preys);

    auto eng = std::mt19937{ 1337 };
    auto dis = std::uniform_real_distribution<>{ -10, 10 };

    std::ranges::generate(preys, [&]() -> Prey {
        return {
            {dis(eng), dis(eng)},
            {dis(eng), dis(eng)}
        };});

}

void Model::update(const double time_delta)
{
    time += time_delta;
    for (auto& prey : preys)
    {
        prey.update(time_delta, environment);
    }
}

void Model::finalize()
{}