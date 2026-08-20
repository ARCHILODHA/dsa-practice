#include <iostream>
using namespace std;

int addNumbers(int a, int b) {
    while (b != 0) {
        int carry = a & b;

        a = a ^ b;
        b = carry << 1;
    }

    return a;
}

int main() {
    int a = 15;
    int b = 27;

    cout << a << " + " << b << " = "
         << addNumbers(a, b) << endl;

    return 0;
}
