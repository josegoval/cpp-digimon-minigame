#pragma once

#include "player/player.h"

class game
{
    int battles_;
    player player_;
public:
    game();

    void report_battle_results(const digimon& winner, const digimon& loser);
    void resolve_battle(digimon& enemy);
    void next_battle();
    void choose_initial_digimon();
    void start_the_battles();
    void begin_game();
};
