#include "digimon.h"

#include "../utils/random/random.h"

bool digimon::is_critical_strike() const
{
    return get_random_float_from_0_1() <= critical_strike_chance_;
}

digimon::digimon(const std::string& name, const int& health, const float& damage_reduction, const int& attack_power,
                 const float& critical_strike_chance): name_(std::move(name)), health_(health),
                                                       damage_reduction_(damage_reduction), attack_power_(attack_power),
                                                       critical_strike_chance_(critical_strike_chance)
{
    
}

float digimon::attack() const
{
    return is_critical_strike() ? attack_power_ * 2 : attack_power_;
}

void digimon::take_damage(float damage)
{
    health_ -= damage * (1 - damage_reduction_);
}

bool digimon::is_alive() const
{
    return health_ > 0;
}
