#include <bits/stdc++.h>
using namespace std;

int integerReplacement(int n) {
    long long num = n;
    int operations = 0;

    while (num != 1) {

        if (num % 2 == 0) {
            num /= 2;
        }
        else if (num == 3 || num % 4 == 1) {
            num--;
        }
        else {
            num++;
        }

        operations++;
    }

    return operations;
}

int main() {
    int n;
    cin >> n;

    cout << integerReplacement(n);

    return 0;
}
