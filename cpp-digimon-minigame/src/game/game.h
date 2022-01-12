#pragma once
#include <string>
#include <vector>

#include "../digimon/digimon.h"

class game
{
    std::string player_name_;
    
public:
    std::string player_name() const;
    void set_player_name(const std::string& player_name);
    void set_player_name(const std::istream& cin);
    void choose_initial_digimon();
    void begin_game();
};
