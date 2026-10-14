#include <iostream>
#include <cmath>
using namespace std;

double AREA(double radius)
{
    return 3.14 * radius * radius;
}

double AREA(double length, double breadth)
{
    return length * breadth;
}

double AREA(double a, double b, double c)
{
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    int choice;
    double a = 0.0, b = 0.0, c = 0.0;

    cout << "\n------ MENU ------\n";
    cout << "\t1. Circle\n";
    cout << "\t2. Rectangle\n";
    cout << "\t3. Triangle\n";
    cout << "\t4. Exit\n";
    cout << "------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter radius of circle: ";
        cin >> a;
        cout << "\nArea : " << AREA(a);
        break;

    case 2:
        cout << "Enter length and breadth of rectangle: ";
        cin >> a >> b;
        cout << "\nArea : " << AREA(a, b);
        break;

    case 3:
        cout << "Enter three sides of triangle: ";
        cin >> a >> b >> c;
        cout << "\nArea : " << AREA(a, b, c);
        break;

    case 4:
        cout << "\nExiting program...";
        break;

    default:
        cout << "\nInvalid choice. Please try again.";
    }
    return 0;
}
