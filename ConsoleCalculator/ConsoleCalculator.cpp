// ConsoleCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int mult(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    if (b == 0) {
        cout << "Cannot divide by 0." << endl;
    }
    return (float) a / b;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int a, b, c, d;
    cout << "Type a number: ";
    cin >> a;
    cout << "Type a second number: ";
    cin >> b;
    cout << "Enter an operation (1 for multiply, 2, for divide, 3 for add, 4 for subtract): ";
    cin >> c;

    if (c > 4) {
        cout << "Invalid." << endl;
        return main();
    }

    if (c == 1) {
        int product = mult(a, b);
        cout << product << endl;
    }
    else if (c == 2) {
        float quotient = divide(a, b);
        cout << quotient << endl;
    }
    else if (c == 3) {
        int sum = add(a, b);
        cout << sum << endl;
    }
    else if (c == 4) {
        int diff = subtract(a, b);
        cout << diff << endl;
    }

    cout << "Go again? (0 for no, 1 for yes) ";
    cin >> d;
    
    if (d > 1) {
        cout << "Invalid." << endl;
    }

    if (d == 0) {
        return 1;
    }
    else {
        return main();
    }

}

