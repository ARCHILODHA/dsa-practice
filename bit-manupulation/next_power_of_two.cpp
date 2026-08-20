#include <iostream>
using namespace std;

unsigned int nextPowerOfTwo(unsigned int n) {
    if (n == 0)
        return 1;

    n--;

    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}

int main() {
    unsigned int n = 19;

    cout << "Number: " << n << endl;
    cout << "Next power of two: " << nextPowerOfTwo(n) << endl;

    return 0;
}
