#include <bits/stdc++.h>
using namespace std;

// Integer division using bit manipulation.
long long divideUsingBits(long long dividend, long long divisor) {
    if (divisor == 0)
        throw invalid_argument("Division by zero");

    bool negative = (dividend < 0) ^ (divisor < 0);

    unsigned long long a = llabs(dividend);
    unsigned long long b = llabs(divisor);

    unsigned long long quotient = 0;

    for (int i = 63; i >= 0; i--) {
        if ((b << i) <= a) {
            a -= (b << i);
            quotient |= (1ULL << i);
        }
    }

    return negative ? -(long long)quotient : (long long)quotient;
}
