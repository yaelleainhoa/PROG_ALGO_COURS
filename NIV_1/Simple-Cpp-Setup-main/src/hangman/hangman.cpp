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
    char letter = 'a';
    while (std::cout << "Enter a letter : " && !(std::cin >> letter)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That's not a letter, please try again....\n";
    }
    return letter;
}

int position_letter(char letter, std::string word)
{
    int                    position = -1;
    std::string::size_type i        = 0;
    while (i < word.length()) {
        if (word[i] == letter) {
            position = i;
            i        = word.length() + 1;
        }
    }
    return position;
}

void replace_letter(char letter, std::string& word, int position)
{
    word.replace(position, 1, letter.str());
}
