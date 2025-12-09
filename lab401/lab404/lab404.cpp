// lab404.cpp : Generates multiplication table for the last two digits of a student ID.

#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
    int value = -1;

    // Prompt until we get a valid 0..99 value
    while (true) {
        std::cout << "Enter the last two digits of your student ID (0-99): ";
        if (!(std::cin >> value)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 0 and 99.\n";
            continue;
        }
        if (value >= 0 && value <= 99) break;
        std::cout << "Value out of range. Please enter 0..99.\n";
    }

    std::cout << "\nMultiplication table for " << value << " (1 to 12):\n\n";
    for (int i = 1; i <= 12; ++i) {
        std::cout << std::setw(2) << value << " x "
                  << std::setw(2) << i << " = "
                  << std::setw(3) << (value * i) << '\n';
    }

    return 0;
}
