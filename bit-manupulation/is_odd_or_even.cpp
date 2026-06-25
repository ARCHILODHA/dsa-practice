#include <iostream>
using namespace std;

string check(int n) {
    return (n & 1) ? "Odd" : "Even";
}

int main() {
    cout << check(17);
    return 0;
}
