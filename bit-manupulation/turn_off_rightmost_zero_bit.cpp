#include <bits/stdc++.h>
using namespace std;

// Turn off the rightmost zero bit of n.
int turnOffRightmostZeroBit(int n) {
    return n & (n + 1);
}
