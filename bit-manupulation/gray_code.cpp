#include <iostream>
using namespace std;

int grayCode(int n) {
    return n ^ (n >> 1);
}

int main() {
    cout << grayCode(7);
    return 0;
}
