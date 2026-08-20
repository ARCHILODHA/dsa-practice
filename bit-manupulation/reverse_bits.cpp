#include <iostream>
using namespace std;

unsigned int reverseBits(unsigned int n) {
    unsigned int result = 0;

    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }

    return result;
}

int main() {
    unsigned int n = 13;

    cout << "Original number: " << n << endl;
    cout << "Reversed bits: " << reverseBits(n) << endl;

    return 0;
}
