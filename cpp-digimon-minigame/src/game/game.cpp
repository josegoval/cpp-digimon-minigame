#include "game.h"

#include <iostream>

#include "../digimon/digimon_generator.h"
#include "../menu/Menu.h"
#include "../utils/print/print.h"
#include "../utils/random/random.h"

std::string transform_digimon_to_string(digimon digimon)
{
    return digimon.name();
}

std::vector<std::string> format_digimons_to_strings(const std::vector<digimon*>& digimons)
{
    std::vector<std::string> digimon_names;
    digimon_names.reserve(digimons.size());
    for (const auto& digimon : digimons)
    {
        digimon_names.emplace_back(digimon->name());
    }
    return digimon_names;
}

game::game()
{
    battles_ = 0;
    player_ = player{};
}

void game::report_battle_results(const digimon& winner, const digimon& loser)
{
    println(loser.name() + " can't continue...");
    println(winner.name() + " has won the battle!");
}

void game::resolve_battle(digimon* enemy)
{
    bool is_player_attacking_first;
    digimon* first_digimon;
    digimon* second_digimon;

    do
    {
        is_player_attacking_first = get_random_int(0,2) < 2;
        first_digimon = is_player_attacking_first ? player_.digimon : enemy;
        second_digimon = is_player_attacking_first ? enemy : player_.digimon; 
        second_digimon->take_damage(first_digimon->attack());
        if (!second_digimon->is_alive())
        {
            report_battle_results(*first_digimon, *second_digimon);
            return;
        };
        first_digimon->take_damage(second_digimon->attack());
    }
    while (first_digimon->is_alive());
    report_battle_results(*second_digimon, *first_digimon);
}

void game::next_battle()
{
    ++battles_;
    digimon* enemy = generate_random_digimon();
    println("Battle number " + std::to_string(battles_) + "!");
    println("You play against "+ enemy->name());
    resolve_battle(enemy);
}

void game::choose_initial_digimon()
{
    std::vector<digimon*> digimons = generate_random_digimons(3);
    const menu choose_digimon_menu("Which digimon would you like to pick?", format_digimons_to_strings(digimons));
    const short option = choose_digimon_menu.display_and_select_option();
    player_.digimon = digimons.at(option);
    println("You have selected " + player_.digimon->name() + "! Congratulations!");
}

void game::start_the_battles()
{
    println("Let's the battles begin!");
    do
    {
        next_battle();
    }
    while (player_.digimon->is_alive());
    println("You have survived "+ std::to_string(battles_)+ " battles!");
}

void game::begin_game()
{
    println("Welcome to Digimon Arena!");
    println("What is your name?");
    std::cin >> this->player_.name;
    println("Welcome " + this->player_.name + "!");
    choose_initial_digimon();
    start_the_battles();
}
