#include <iostream>
using namespace std;

int flipBits(int n) {
    return ~n;
}

int main() {
    cout << flipBits(10);
    return 0;
}
