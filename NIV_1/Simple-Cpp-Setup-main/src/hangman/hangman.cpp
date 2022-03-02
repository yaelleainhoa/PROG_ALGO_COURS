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

class Hangman_party {
public:
    Hangman_party()
        : _word{random_words()}
        , _hangman(_word.size(), '*')
    {
    }

    void test_letter(char letter);
    void replace_letter(char letterToInsert, std::size_t position);
    void loose_lives();

    bool is_word_guessed() const { return (_word == _hangman); };
    bool is_player_alive() const { return (_lives > 0); };

    int         get_lives() const { return _lives; };
    std::string get_hangman() const { return _hangman; };
    std::string get_word() const { return _word; };

private:
    std::string _word;
    std::string _hangman;
    int         _lives = 10;
};

void Hangman_party::replace_letter(char letterToInsert, std::size_t position)
{
    char        letter = static_cast<char>(tolower(letterToInsert));
    std::string str_letter(1, letter);
    _hangman.replace(position, 1, str_letter);
}

std::size_t position_letter(char letter_to_test, std::string word, std::size_t last_position)
{
    char        letter   = static_cast<char>(tolower(letter_to_test));
    std::size_t position = word.find(letter, last_position);
    return position;
}

void Hangman_party::loose_lives()
{
    std::cout << "Ouch, not quite...\n \n";
    _lives--;
}

void Hangman_party::test_letter(char letter)
{
    std::size_t pos               = 0;
    std::size_t last_pos          = -1;
    bool        is_letter_in_word = false;
    while (pos != std::string::npos) {
        pos      = position_letter(letter, _word, last_pos + 1);
        last_pos = pos;
        if (last_pos != std::string::npos) {
            this->replace_letter(letter, last_pos);
            is_letter_in_word = true;
        }
    }
    if (!is_letter_in_word) {
        loose_lives();
    }
}

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
    std::cout << "hangman : " << hangman << std::endl;
    std::cout << "LIVES : " << lives << std::endl
              << std::endl;
    ;
}

void play_hangman()
{
    Hangman_party party;
    char          letter = '*';
    std::cout << "Try to guess the following word : " << std::endl;
    while (party.is_player_alive() && !party.is_word_guessed()) {
        show_lives(party.get_lives(), party.get_hangman());
        letter = get_letter_from_user();
        party.test_letter(letter);
    }
    if (party.is_word_guessed()) {
        show_win_message(party.get_hangman());
    }
    else {
        show_loose_mesage(party.get_word());
    }
}