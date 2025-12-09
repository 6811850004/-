#include <iostream>
#include <cmath>
#include <cstdint>

// Returns true if n is prime (works for 64-bit unsigned integers)
bool isPrime(unsigned long long n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;

    unsigned long long limit = static_cast<unsigned long long>(std::sqrt((long double)n));
    for (unsigned long long i = 5; i <= limit; i += 6) {
        if (n % i == 0) return false;
        if (n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::cout << "Enter non-negative integers to check for primality (Ctrl+Z then Enter to stop):\n";
    unsigned long long value;
    while (std::cin >> value) {
        if (isPrime(value)) {
            std::cout << value << " is prime\n";
        } else {
            std::cout << value << " is not prime\n";
        }
    }
    return 0;
}