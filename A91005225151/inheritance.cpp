#include <iostream>
using namespace std;

class Student {
public:
    int rollno;
    char name[100];
    void input() {
        cout << "Enter name :";
        cin >> name;
        cout << "Enter roll number :";
        cin >> rollno;
    }
    void display() {
        cout << "The name of the student is: " << name << endl;
        cout << "The roll number of the student is: " << rollno << endl;
    }
};

class Exam : public Student {
public:
    int marks[6];
    void input() {
        Student::input();
        cout << "Enter marks of 6 subjects:\n";
        for (int i = 0; i < 6; i++) {
            cin >> marks[i];
        }
    }
    void display() {
        Student::display();
        cout << "Marks: ";
        for (int i = 0; i < 6; i++) {
            cout << marks[i] << " ";
        }
    }
};

class Result : public Exam {
public:
    float avg = 0.0f;
    float sum = 0.0f;
    void calculate() {
        sum = 0.0f;
        for (int i = 0; i < 6; i++) {
            sum += marks[i];
        }
        avg = sum / 6.0f;
    }
    void display() {
        Exam::display();
        cout << "\nThe total marks is:" << sum;
        cout << "\nThe average of the marks is:" << avg << endl;
    }
};

int main() {
    Result S;
    S.input();
    S.calculate();
    S.display();
    return 0;
}
