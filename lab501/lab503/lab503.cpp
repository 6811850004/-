#include <iostream>
#include <cmath>

using namespace std;

// Prototype
void swapValue(int a, int b);
void swapReference(int &a, int &b);

void swapValue(int a, int b) {
    // swap local copies (no effect on caller)
    int temp = a;
    a = b;
    b = temp;
}

void swapReference(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10;
    int b = 20;

    cout << "Before swap: a = " << a << ", b = " << b << endl;

    // Call by value: original a and b remain unchanged
    swapValue(a, b);
    cout << "After swap (Call by Value): a = " << a << ", b = " << b << endl;

    // Call by reference: original a and b are swapped
    swapReference(a, b);
    cout << "After swap (Call by Reference): a = " << a << ", b = " << b << endl;

    return 0;
}