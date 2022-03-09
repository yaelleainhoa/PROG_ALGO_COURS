#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>
#include "../guess_the_number/guess_the_number.h"
#include "../hangman/hangman.h"

struct Game {
    Game(std::string name)
        : m_name(name){};

private:
    std::string m_name;

public:
    std::string get_name() const { return m_name; };
};

void display_game(Game game, int command)
{
    std::cout << command << " : Play " << game.get_name() << std::endl;
}

void beginning_menu(const std::array<Game, 2>& games)
{
    std::cout << "What do you want to do ?" << std::endl
              << std::endl;
    // int length = static_cast<int>(games.size());
    for (int i = 0; i < 2; i++) {
        display_game(games.at(i), i);
    };
    std::cout << std::endl;
}

void menu()
{
    Game                guess_the_number("Guess the number");
    Game                hangman("Hangman");
    std::array<Game, 2> games = {guess_the_number, hangman};
    enum Games { GUESS_THE_NUMBER = 0,
                 HANGMAN          = 1 };
    beginning_menu(games);
    int  user_command  = -1;
    bool valid_command = false;
    while (!valid_command && std::cin >> user_command) {
        switch (user_command) {
        case GUESS_THE_NUMBER:
            valid_command = true;
            play_guess_the_number();
            break;
        case HANGMAN:
            valid_command = true;
            play_hangman();
            break;
        }
        std::cout << "not valid command " << std::endl;
    }
}