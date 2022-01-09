#pragma once
#include <iostream>
#include <string>
#include <vector>

class menu
{
    std::string question_;
    std::vector<std::string> options_;

    short get_selected_option() const;

public:
    explicit menu(std::string question, std::vector<std::string> options);

    short display_and_select_option() const;
};
