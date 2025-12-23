#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Prototype
double circleArea(double radius);
int rectArea(int width, int height);
int maxOfThree(int a, int b, int c);

double circleArea(double radius) {
    const double PI = acos(-1.0);
    return PI * radius * radius;
}

int rectArea(int width, int height) {
    return width * height;
}

int maxOfThree(int a, int b, int c) {
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

int main()
{
    double radius = 5.0;
    int width = 10;
    int height = 5;

    double cArea = circleArea(radius);
    int rArea = rectArea(width, height);

    cout << fixed << setprecision(2);
    cout << "Circle Area = " << cArea << endl;
    cout << "Rectangle Area = " << rArea << endl;

    // Lab 2: Find Maximum
    int a = 7, b = 15, c = 12;
    int maximum = maxOfThree(a, b, c);
    cout << "Maximum value is: " << maximum << endl;

    return 0;
}

