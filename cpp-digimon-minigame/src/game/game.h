#pragma once

#include "player/player.h"

class game
{
    player player_;
public:
    game();

    void choose_initial_digimon();
    void begin_game();
};
