#include <iostream>
using namespace std;

int rightmostSetBit(int n) {
    return n & (-n);
}

int main() {
    cout << rightmostSetBit(12);
    return 0;
}
