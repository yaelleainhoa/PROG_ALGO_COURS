#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>
#include "../guess_the_number/guess_the_number.h"
#include "../hangman/hangman.h"

void display_game(std::string game, int command)
{
    std::cout << command << " : Play " << game << std::endl;
}

void beginning_menu(const std::array<std::string, 2>& games)
{
    std::cout << "What do you want to do ?" << std::endl
              << std::endl;
    // int length = static_cast<int>(games.size());
    for (int i = 0; i < 2; i++) {
        display_game(games.at(i), i);
    };
    std::cout << std::endl;
}

char get_user_command()
{
    char user_command;
    while (!(std::cin >> user_command)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please try again....\n";
    }
    return user_command;
}

void play(char user_command)
{
    enum Games { GUESS_THE_NUMBER = '0',
                 HANGMAN          = '1',
                 QUIT             = 'q' };
    switch (user_command) {
    case GUESS_THE_NUMBER:
        play_guess_the_number();
        break;
    case HANGMAN:
        play_hangman();
        break;
    case QUIT:
        std::cout << "See you next time" << std::endl;
        break;
    default:
        std::cout << "I don't know this command.. Please try again" << std::endl;
        user_command = get_user_command();
        play(user_command);
        break;
    }
}

void menu()
{
    std::array<std::string, 2> games = {"Guess the number", "Hangman"};
    beginning_menu(games);
    char user_command = get_user_command();
    play(user_command);
}