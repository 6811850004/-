
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Prototype
double circleArea(double radius);
int rectArea(int width, int height);

double circleArea(double radius) {
    const double PI = acos(-1.0);
    return PI * radius * radius;
}

int rectArea(int width, int height) {
    return width * height;
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

    return 0;
}

