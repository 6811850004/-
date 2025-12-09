
#include <iostream>

int main()
{
    long long sum = 0;
    for (int i = 1; i <= 100; ++i) {
        sum += i;
    }

    std::cout << "Sum of 1 to 100 is: " << sum << '\n';
    return 0;
}
