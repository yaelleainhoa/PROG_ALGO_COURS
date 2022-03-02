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
    int              user_action      = 0;
    std::vector<int> actions_possible = actions();
    while (std::cin >> user_action && !(std::find(actions_possible.begin(), actions_possible.end(), user_action) != actions_possible.end())) {
        std::cout << "Sorry, I don't know this command..." << std::endl;
    }
    if (user_action == 1) {
        play_guess_the_number();
    }
    else if (user_action == 2) {
        play_hangman();
    }
    else {
        std::cout << "See you next time, bye !" << std::endl;
    }
}