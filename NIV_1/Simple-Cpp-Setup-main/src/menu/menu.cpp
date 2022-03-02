#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "../guess_the_number/guess_the_number.h"
#include "../hangman/hangman.h"

const std::vector<int>& actions()
{
    static const std::vector<int> list_of_actions = {1, 2, static_cast<int>('q')};
    return list_of_actions;
}

void beginning_menu()
{
    std::cout << "What do you want to do ?" << std::endl
              << std::endl;
    std::cout << "1 : Play 'Guess the number'" << std::endl;
    std::cout << "2 : Play 'Hangman'" << std::endl;
    std::cout << "q : quit :'( (why?)" << std::endl
              << std::endl;
}

void menu()
{
    beginning_menu();
    char             user_action      = '0';
    int              real_action      = 0;
    std::vector<int> actions_possible = actions();
    bool             action_allowed   = false;
    while (!action_allowed && std::cin >> user_action) {
        if (static_cast<int>(user_action) < 58 or static_cast<int>(user_action) < 48) {
            real_action = static_cast<int>(user_action) - 48;
        }
        else {
            real_action = static_cast<int>(user_action);
        }
        if (std::find(actions_possible.begin(), actions_possible.end(), real_action) != actions_possible.end()) {
            action_allowed = true;
        }
        else {
            std::cout << "Sorry, I don't know this command... try again please : " << std::endl;
        }
    }
    if (real_action == 1) {
        play_guess_the_number();
    }
    else if (real_action == 2) {
        play_hangman();
    }
    else {
        std::cout << "See you next time, bye !" << std::endl;
    }
}