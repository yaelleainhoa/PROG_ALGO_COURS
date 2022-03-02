#include <array>
#include <iostream>
#include <limits>
#include "../rand/rand.h"

std::string random_words()
{
    static const std::array<std::string, 15> list_of_words = {"mot", "coucou", "chat", "chien", "rat", "lys",
                                                              "acajou", "azimut", "basson", "cercle", "coccyx",
                                                              "thym", "corse", "rhum", "tyran"};
    return list_of_words.at(rand(0, list_of_words.size()));
}

// class Hangman {
// public:
//     Hangman(std::string word)
//         : _word{word}
//         , _hangman(word.size(), '*') // The invariant is enforced by the constructor here, and no public function of this class allows users to break the invariant, so we can guarantee that it will be preserved!
//     {
//     }

//     void test_letter()

// private:
//     std::string _word;
//     std::string _hangman;
// };

char get_letter_from_user()
{
    char letter      = 'a';
    bool is_a_letter = false;
    while (!is_a_letter) {
        std::cout << "Enter a letter : ";
        std::cin >> letter;
        if (!((letter >= 97 && letter <= 122) || (letter <= 90 && letter >= 65))) {
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

std::size_t position_letter(char letter_to_test, std::string word, std::size_t last_position)
{
    char        letter   = static_cast<char>(tolower(letter_to_test));
    std::size_t position = word.find(letter, last_position);
    return position;
}

void replace_letter(char letterToInsert, std::string& hangman, std::size_t position)
{
    char        letter = static_cast<char>(tolower(letterToInsert));
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

void show_win_message(std::string word)
{
    std::cout << word << std::endl;
    std::cout << "Congratulation !" << std::endl;
}

void show_loose_mesage(std::string word)
{
    std::cout << "You lost... the word was " << word << std::endl;
}

void show_lives(int lives, std::string hangman)
{
    std::cout << "LIVES : " << lives << std::endl;
    std::cout << "hangman : " << hangman << std::endl
              << std::endl;
}

void hangman()
{
    std::string word = random_words();
    std::string hangman;
    char        letter;
    bool        is_letter_in_word = false;
    int         lives             = 10;
    for (std::size_t i = 0; i < word.length(); i++) {
        hangman.append("*");
    }
    while (hangman != word && lives > 0) {
        show_lives(lives, hangman);
        letter            = get_letter_from_user();
        is_letter_in_word = test_letter(letter, word, hangman);
        loose_lives(lives, is_letter_in_word);
    }
    if (hangman == word) {
        show_win_message(hangman);
    }
    else {
        show_loose_mesage(word);
    }
}