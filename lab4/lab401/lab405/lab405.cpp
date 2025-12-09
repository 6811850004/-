// lab405.cpp : Number guessing game (random 1-100). Compiles with C++14.
//

#include <iostream>
#include <random>
#include <string>
#include <limits>

int main()
{
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(1, 100);

    bool play = true;
    while (play) {
        int secret = dist(rng);
        int guess = 0;
        int attempts = 0;

        std::cout << "I have chosen a number between 1 and 100. Try to guess it.\n";

        while (true) {
            std::cout << "Enter your guess: ";
            if (!(std::cin >> guess)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter an integer.\n";
                continue;
            }
            if (guess < 1 || guess > 100) {
                std::cout << "Please guess a number between 1 and 100.\n";
                continue;
            }

            ++attempts;
            if (guess < secret) {
                std::cout << "Too low.\n";
            } else if (guess > secret) {
                std::cout << "Too high.\n";
            } else {
                std::cout << "Correct! The number was " << secret << ". Attempts: " << attempts << '\n';
                break;
            }
        }

        std::cout << "Play again? (y/n): ";
        char reply = 'n';
        while (std::cin >> reply) {
            if (reply == 'y' || reply == 'Y') { play = true; break; }
            if (reply == 'n' || reply == 'N') { play = false; break; }
            std::cout << "Please enter 'y' or 'n': ";
        }
    }

    return 0;
}
