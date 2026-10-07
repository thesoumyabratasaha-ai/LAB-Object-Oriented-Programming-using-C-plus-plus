#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    char name[64];
    int age;
    char address[64];
    
    // Salary divided into components
    float basic_salary;
    float hra;
    float da;
    float total_salary;

public:
    // Constructor to initialize data and calculate salary components
    Person() {
        // Default initialization for safety
        age = 0;
        basic_salary = 0.0f;
        hra = 0.0f;
        da = 0.0f;
        total_salary = 0.0f;
        name[0] = '\0';
        address[0] = '\0';
    }

    // Function to handle secure data input
    void inputDetails(int index) {
        cout << "\n--- Enter Details for Person " << (index + 1) << " ---" << endl;
        
        cout << "Enter Name: ";
        cin.getline(name, 100);
        
        cout << "Enter Age: ";
        cin >> age;
        // cin.ignore(); // Clear newline buffer
        
        cout << "Enter Address: ";
        cin.getline(address, 64);
        
        cout << "Enter Basic Salary: $";
        cin >> basic_salary;
        // cin.ignore();
        
        // Calculate salary components
        hra = basic_salary * 0.20f; // 20% HRA
        da = basic_salary * 0.50f;  // 50% DA
        total_salary = basic_salary + hra + da;
    }

    // (b) Method to display the developed salary slip
    void displaySalarySlip() const {
        cout << "------------ SALARY SLIP -----------" << endl;
        cout << "Name:    " << name << endl;
        cout << "Age:     " << age << " years" << endl;
        cout << "Address: " << address << endl;
        cout << "------------------------------------" << endl;
        cout << "Basic Salary:  " << basic_salary << endl;
        cout << "HRA (20%):     " << hra << endl;
        cout << "DA (50%):      " << da << endl;
        cout << "------------------------------------" << endl;
        cout << "TOTAL SALARY:  " << total_salary << endl;
        cout << "------------------------------------" << endl;
    }

    // Getter function for age to use in the inline function
    int getAge() const {
        return age;
    }
};

// (a) Inline function to find the youngest and eldest person using an array
inline void findExtremes(const Person arr[], int size, int &youngestIdx, int &eldestIdx) {
    int maxAge = arr[0].getAge();
    int minAge = arr[0].getAge();
    youngestIdx = 0;
    eldestIdx = 0;

    for (int i = 1; i < size; i++) {
        int currentAge = arr[i].getAge();
        if (currentAge > maxAge) {
            maxAge = currentAge;
            eldestIdx = i;
        }
        if (currentAge < minAge) {
            minAge = currentAge;
            youngestIdx = i;
        }
    }
}

int main() {
    const int SIZE = 10;
    Person people[SIZE]; // Array of 10 Person objects calling default constructor

    // Get details for all 10 people
    cout << "Please fill out the information for " << SIZE << " individuals." << endl;
    for (int i = 0; i < SIZE; i++) {
        people[i].inputDetails(i);
    }

    // (b) Display Salary Slips for everyone
    cout << "\n\nPrinting all developed salary slips..." << endl;
    for (int i = 0; i < SIZE; i++) {
        people[i].displaySalarySlip();
    }

    // (a) Execute the inline function to determine age extremes
    int youngestIdx = 0;
    int eldestIdx = 0;
    findExtremes(people, SIZE, youngestIdx, eldestIdx);

    cout << "\n====================================" << endl;
    cout << "           AGE ANALYSIS             " << endl;
    cout << "====================================" << endl;
    cout << "The YOUNGEST person is at index [" << youngestIdx << "] with an age of " << people[youngestIdx].getAge() << " years." << endl;
    cout << "The ELDEST person is at index [" << eldestIdx << "] with an age of " << people[eldestIdx].getAge() << " years." << endl;
    cout << "====================================" << endl;

    return 0;
}
