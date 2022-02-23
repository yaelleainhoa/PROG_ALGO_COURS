#include <iostream>
#include <random>

int rand(int min, int max)
{
    static std::default_random_engine  generator{std::random_device{}()};
    std::uniform_int_distribution<int> distribution{min, max};
    return distribution(generator);
}

int get_int_from_user()
{
    int n = 0;
    std::cout << "Guess the number : ";
    std::cin >> n;
    return n;
}

int main()
{
    std::cout << "Hello World\n";
}