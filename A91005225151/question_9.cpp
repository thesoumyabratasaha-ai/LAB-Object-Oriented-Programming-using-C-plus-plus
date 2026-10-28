#include <iostream>
using namespace std;

class Class {
public:
    int num;

    friend void swapNumbers(Class &a, Class &b);
};

void swapNumbers(Class &a, Class &b) {
    int temp = a.num;
    a.num = b.num;
    b.num = temp;
}

int main() {
    Class A, B; 
    cout << "Enter value for Class A: ";
    cin >> A.num; 
    cout << "Enter value for Class B: ";
    cin >> B.num;

    cout << "\n--- Before Swapping ---" << endl;
    cout << "A.num: " << A.num << "\tB.num: " << B.num << endl;

    swapNumbers(A, B); 

    cout << "\n--- After Swapping ---" << endl; 
    cout << "A.num: " << A.num << "\tB.num: " << B.num << endl;

    return 0;
}
