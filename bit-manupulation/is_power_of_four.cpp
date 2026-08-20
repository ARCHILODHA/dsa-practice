#include <iostream>
using namespace std;

bool isPowerOfFour(int n) {
    if (n <= 0)
        return false;

    // Power of four has exactly one set bit,
    // and that bit occurs at an even position.
    return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
}

int main() {
    int n = 64;

    if (isPowerOfFour(n))
        cout << n << " is a power of four." << endl;
    else
        cout << n << " is not a power of four." << endl;

    return 0;
}
