﻿#pragma once
#include <string>

class digimon
{
    std::string name_;
    int health_;
    float damage_reduction_;
    int attack_power_;
    float critical_strike_chance_;

    bool is_critical_strike() const;
public:
    digimon(const std::string& name, const int& health, const float& damage_reduction, const int& attack_power, const float& critical_strike_chance);

    float attack() const;
    void take_damage(float damage);
    bool is_alive() const;
};
