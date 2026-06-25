#include <iostream>
using namespace std;

int setKthBit(int n, int k) {
    return n | (1 << k);
}

int main() {
    cout << setKthBit(10, 1);
    return 0;
}
