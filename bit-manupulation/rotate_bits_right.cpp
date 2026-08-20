#include <iostream>
using namespace std;

unsigned int rotateRight(unsigned int n, int shift) {
    const int bits = 32;
    shift %= bits;

    return (n >> shift) | (n << (bits - shift));
}

int main() {
    unsigned int n = 20;
    int shift = 2;

    cout << "Number: " << n << endl;
    cout << "After right rotation by " << shift << " bits: "
         << rotateRight(n, shift) << endl;

    return 0;
}
