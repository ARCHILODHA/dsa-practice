#include <iostream>
using namespace std;

bool checkKthBit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    int n = 13, k = 2;
    cout << checkKthBit(n, k);
    return 0;
}
