#include "game.h"

#include <iostream>

#include "../utils/print/print.h"

std::string game::player_name() const
{
    return player_name_;
}

void game::set_player_name(const std::string& player_name)
{
    player_name_ = player_name;
}

void game::set_player_name(const std::istream& cin)
{
    set_player_name(cin);
}

void game::choose_initial_digimon()
{
    
}

void game::begin_game()
{
    println("Welcome to Digimon Arena!");
    println("What is your name?");
    set_player_name(std::cin);
    println("Welcome " + player_name_ + "!");
    choose_initial_digimon();
}
