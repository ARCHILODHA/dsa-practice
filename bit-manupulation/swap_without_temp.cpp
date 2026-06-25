#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 8;

    a ^= b;
    b ^= a;
    a ^= b;

    cout << a << " " << b;
    return 0;
}
