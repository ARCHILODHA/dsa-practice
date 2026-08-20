#include <iostream>
using namespace std;

int subtractNumbers(int a, int b) {
    while (b != 0) {
        int borrow = (~a) & b;

        a = a ^ b;
        b = borrow << 1;
    }

    return a;
}

int main() {
    int a = 25;
    int b = 9;

    cout << a << " - " << b << " = "
         << subtractNumbers(a, b) << endl;

    return 0;
}
