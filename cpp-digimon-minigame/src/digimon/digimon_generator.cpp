#include "digimon_generator.h"

#include "digimon.h"
#include "../utils/random/random.h"

std::vector<std::string> random_digimon_names = {
    "Agumon", "Gabumon", "Monmon", "Angemon", "Andromon", "Bearmon", "Beetamon", "Candlemon", "Chuumon", "DemiDevimon"
};

digimon* generate_random_digimon()
{
    const std::string name = random_digimon_names.at(get_random_int(0,random_digimon_names.size() - 1));
    const int health = get_random_int(300,700);
    const float damage_reduction = static_cast<float>(get_random_int(5, 70)) / 100;
    const int attack_power = get_random_int(130,327);
    const float critical_strike_chance = static_cast<float>(get_random_int(5, 70)) / 100;
    return new digimon(name, health, damage_reduction,attack_power, critical_strike_chance);
}

std::vector<digimon*> generate_random_digimons(int amount)
{
    std::vector<digimon*> digimons;
    digimons.reserve(amount);
    // ReSharper disable once CppJoinDeclarationAndAssignment
    bool is_repeated;
    while (amount > 0)
    {
        is_repeated = false;
        digimon* next_digimon = generate_random_digimon();
        for (const auto& digimon : digimons)
        {
            if (digimon->name() == next_digimon->name())
            {
                is_repeated = true;
                break;
            }
        }
        if (!is_repeated)
        {
            digimons.emplace_back(next_digimon);
            --amount;
        }
    }
    return digimons;
}
