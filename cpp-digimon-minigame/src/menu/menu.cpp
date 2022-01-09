#include "Menu.h";

short menu::get_selected_option() const
{
    short option;
    std::cout << "Insert your option:" << std::endl;
    std::cin >> option;
    while (option < 1 || option > options_.size())
    {
        std::cout << "Please insert a valid option:" << std::endl;
        std::cin >> option;
    }
    return option;
}

menu::menu(const std::string question,const std::vector<std::string> options)
{
    this->question_ = question;
    this->options_ = options;
}

short menu::display_and_select_option() const
{
    std::cout<< this->question_ << std::endl;
    for (short i = 0; i < options_.size(); ++i)
    {
        std::cout<< "["<< i << "] - " + options_[i] + "." << std::endl;
    }
    return get_selected_option();
}
