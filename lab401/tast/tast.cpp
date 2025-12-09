#include <iostream>

int main()
{
    long long sum = 0;
    int i = 1;

    while (sum  <= 500) {
        sum += i;
        std::cout <<  sum <<  '\n';
        ++i;
    }

    
    return 0;
}

