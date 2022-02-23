#include "guess_the_number.h"
#include <iostream>
#include <limits>
#include "../rand/rand.h"

int get_int_from_user()
{
    int num = 0;
    while (std::cout << "Guess the number : " && !(std::cin >> num)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That's not a number, please try again....\n";
    }
    return num;
}

void play_guess_the_number()
{
    std::cout << "Guess the number I have in mind, between 0 and 100 ! \n \n";
    int  number_to_guess   = rand(0, 100);
    int  number_user       = -1;
    bool is_number_guessed = false;
    while (!is_number_guessed) {
        number_user = get_int_from_user();
        if (number_user > number_to_guess) {
            std::cout << "It's smaller..\n";
        }
        else if (number_user < number_to_guess) {
            std::cout << "It's greater..\n";
        }
        else {
            is_number_guessed = true;
        }
    }
    std::cout << "Yayy!" << std::endl;
}