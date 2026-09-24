#include <bits/stdc++.h>
using namespace std;

// Clears the rightmost set bit.
int clearRightmostSetBit(int n) {
    return n & (n - 1);
}
