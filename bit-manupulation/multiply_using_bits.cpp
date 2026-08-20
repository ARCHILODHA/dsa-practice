#include <iostream>
using namespace std;

int multiply(int a, int b) {
    int result = 0;

    while (b > 0) {
        if (b & 1)
            result += a;

        a <<= 1;
        b >>= 1;
    }

    return result;
}

int main() {
    int a = 7;
    int b = 6;

    cout << a << " * " << b << " = "
         << multiply(a, b) << endl;

    return 0;
}
