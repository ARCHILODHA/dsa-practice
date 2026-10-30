#include <bits/stdc++.h>
using namespace std;

long long reverseHelper(long long n, long long result) {
    if (n == 0) return result;

    return reverseHelper(n / 10, result * 10 + n % 10);
}

int main() {
    long long n;
    cin >> n;

    bool negative = n < 0;
    n = abs(n);

    long long result = reverseHelper(n, 0);

    if (negative) result = -result;

    cout << result;
    return 0;
}
