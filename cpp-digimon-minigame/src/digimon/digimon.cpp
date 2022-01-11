#include "digimon.h"

digimon::digimon(const std::string& name, const int& health, const float& damage_reduction, const int& attack_power,
                 const float& critical_strike_chance): name_(std::move(name)), health_(health),
                                                       damage_reduction_(damage_reduction), attack_power_(attack_power),
                                                       critical_strike_chance_(critical_strike_chance)
{
    
}
