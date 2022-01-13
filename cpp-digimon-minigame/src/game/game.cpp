#include "game.h"

#include <iostream>

#include "../digimon/digimon_generator.h"
#include "../menu/Menu.h"
#include "../utils/print/print.h"

std::string transform_digimon_to_string(digimon digimon)
{
    return digimon.name();
}

std::vector<std::string> format_digimons_to_strings(const std::vector<digimon>& digimons)
{
    std::vector<std::string> digimon_names;
    digimon_names.reserve(digimons.size());
    for (const auto& digimon : digimons)
    {
        digimon_names.emplace_back(digimon.name());
    }
    return digimon_names;
}

game::game()
{
    player_ = player{};
}

void game::choose_initial_digimon()
{
    const std::vector<digimon> digimons = generate_random_digimons(3);
    const menu choose_digimon_menu("Which digimon would you like to pick?", format_digimons_to_strings(digimons));
    const short option = choose_digimon_menu.display_and_select_option();
    player_.digimon = const_cast<digimon*>(&digimons.at(option));
    println("You have selected " + player_.digimon->name() + "! Congratulations!");
    println("Let's the battle begin!");
}

void game::begin_game()
{
    println("Welcome to Digimon Arena!");
    println("What is your name?");
    std::cin >> this->player_.name;
    println("Welcome " + this->player_.name + "!");
    choose_initial_digimon();
}
