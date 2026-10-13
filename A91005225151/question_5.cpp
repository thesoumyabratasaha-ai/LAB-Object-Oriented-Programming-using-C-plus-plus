#include <iostream>
using namespace std;

class Person
{
    char name[64], address[64];
    int age;
    float basic_salary, hra, da, total_salary;

public:
    Person()
    {
        age = 0;
        basic_salary = hra = da = total_salary = 0;
        name[0] = address[0] = '\0';
    }

    void input(int index)
    {
        cout << "\nEnter details for Person " << index + 1 << endl;

        cout << "Name: ";
        cin.getline(name, 64);

        cout << "Age: ";
        cin >> age;
        cin.ignore(1000, '\n');

        cout << "Address: ";
        cin.getline(address, 64);

        cout << "Basic Salary: ";
        cin >> basic_salary;
        cin.ignore(1000, '\n');

        hra = basic_salary * 0.20;
        da = basic_salary * 0.50;
        total_salary = basic_salary + hra + da;
    }

    void display()
    {
        cout << "\n----- SALARY SLIP -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Basic Salary: " << basic_salary << endl;
        cout << "HRA (20%): " << hra << endl;
        cout << "DA (50%): " << da << endl;
        cout << "Total Salary: " << total_salary << endl;
    }

    int getAge()
    {
        return age;
    }
};

inline void findExtremes(Person arr[], int size,
                         int &youngest, int &eldest)
{
    youngest = eldest = 0;

    for (int i = 1; i < size; i++)
    {
        if (arr[i].getAge() < arr[youngest].getAge())
            youngest = i;

        if (arr[i].getAge() > arr[eldest].getAge())
            eldest = i;
    }
}

int main()
{
    int size = 10;
    Person people[10];

    for (int i = 0; i < size; i++)
        people[i].input(i);

    for (int i = 0; i < size; i++)
        people[i].display();

    int youngest, eldest;
    findExtremes(people, size, youngest, eldest);

    cout << "\nYoungest age: "
         << people[youngest].getAge() << endl;
    cout << "Eldest age: "
         << people[eldest].getAge() << endl;

    return 0;
}
