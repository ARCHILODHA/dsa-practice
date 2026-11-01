#include <bits/stdc++.h>
using namespace std;

int findComplement(int num) {
    if (num == 0) return 1;

    unsigned int mask = 0;
    unsigned int temp = num;

    while (temp > 0) {
        mask = (mask << 1) | 1U;
        temp >>= 1;
    }

    return static_cast<int>(mask ^ static_cast<unsigned int>(num));
}

int main() {
    int num;
    cin >> num;

    cout << findComplement(num);

    return 0;
}
