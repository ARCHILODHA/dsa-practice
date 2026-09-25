#include <bits/stdc++.h>
using namespace std;

// Find the 1-based position of the rightmost set bit.
int rightmostSetBitPosition(int n) {
    if (n == 0)
        return -1;

    int position = 1;

    while ((n & 1) == 0) {
        n >>= 1;
        position++;
    }

    return position;
}
