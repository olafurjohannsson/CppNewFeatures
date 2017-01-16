
#include <iostream>
#include <random>

int main() 
{
    std::cout << "Guessing game, guess number between 1-10" << std::endl;
    int random_number;
    std::string guess;
    while (guess != "q") {
        random_number = rand() % 10;
        std::cout << random_number << std::endl;
        std::cout << "Guess the number: ";
        std::cin >> guess;

        if (std::atoi(&guess[0]) == random_number) {
            std::cout << "You guessed correctly!\n";
            break;
        }

        std::cout << guess << std::endl;
    }
    return 0;
}
