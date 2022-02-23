#include <array>
#include <iostream>
#include <limits>
#include "../rand/rand.h"

const std::array<std::string, 15>& random_words()
{
    static const std::array<std::string, 15> list_of_words = {"mot", "coucou", "chat", "chien", "rat", "lys",
                                                              "acajou", "azimut", "basson", "cercle", "coccyx",
                                                              "thym", "corse", "rhum", "tyran"};
    return list_of_words;
}

char get_letter_from_user()
{
    char letter      = 'a';
    bool is_a_letter = false;
    while (!is_a_letter) {
        std::cout << "Enter a letter : ";
        std::cin >> letter;
        if (!((letter >= 97 && letter <= 122) or (letter <= 90 && letter >= 65))) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nThat's not a letter, please try again....\n \n";
        }
        else {
            is_a_letter = true;
        }
    }
    return letter;
}

std::size_t position_letter(char letter, std::string word, std::size_t last_position)
{
    std::size_t position = word.find(letter, last_position);
    return position;
}

void replace_letter(char letter, std::string& hangman, std::size_t position)
{
    std::string str_letter(1, letter);
    hangman.replace(position, 1, str_letter);
}

bool test_letter(char letter, std::string word, std::string& hangman)
{
    std::size_t pos               = 0;
    std::size_t last_pos          = -1;
    bool        is_letter_in_word = false;
    while (pos != std::string::npos) {
        pos      = position_letter(letter, word, last_pos + 1);
        last_pos = pos;
        if (last_pos != std::string::npos) {
            replace_letter(letter, hangman, last_pos);
            is_letter_in_word = true;
        }
    }
    return is_letter_in_word;
}

void loose_lives(int& lives, bool is_letter_in_word)
{
    if (!is_letter_in_word) {
        std::cout << "Ouch, not quite...\n \n";
        lives--;
    }
}

void hangman()
{
    int         index_rand = rand(0, 15);
    std::string word       = random_words().at(index_rand);
    std::string hangman;
    char        letter;
    bool        is_letter_in_word = false;
    int         lives             = 10;
    for (std::size_t i = 0; i < word.length(); i++) {
        hangman.append("_");
    }
    while (hangman != word && lives > 0) {
        std::cout << "LIVES : " << lives << std::endl;
        std::cout << hangman << std::endl;
        letter            = get_letter_from_user();
        is_letter_in_word = test_letter(letter, word, hangman);
        loose_lives(lives, is_letter_in_word);
    }
    if (hangman == word) {
        std::cout << hangman << std::endl;
        std::cout << "Congratulation !" << std::endl;
    }
    else {
        std::cout << "You lost... the word was " << word << std::endl;
    }
}