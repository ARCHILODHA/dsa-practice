#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    long long low = 0, high = x;

    while (low <= high) {
        long long mid = (low + high) / 2;

        if (mid * mid == x)
            return mid;

        if (mid * mid < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}
