#include <iostream>
using namespace std;

void decimalToBinary(int n) {
    if (n == 0) return;
    decimalToBinary(n / 2);
    cout << n % 2;
}

int main() {
    int n = 13;
    decimalToBinary(n);
}
