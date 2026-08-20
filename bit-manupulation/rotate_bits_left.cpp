#include <iostream>
using namespace std;

unsigned int rotateLeft(unsigned int n, int shift) {
    const int bits = 32;
    shift %= bits;

    return (n << shift) | (n >> (bits - shift));
}

int main() {
    unsigned int n = 5;
    int shift = 2;

    cout << "Number: " << n << endl;
    cout << "After left rotation by " << shift << " bits: "
         << rotateLeft(n, shift) << endl;

    return 0;
}
