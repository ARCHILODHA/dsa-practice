#include <iostream>
using namespace std;

int clearKthBit(int n, int k) {
    return n & ~(1 << k);
}

int main() {
    cout << clearKthBit(14, 1);
    return 0;
}
