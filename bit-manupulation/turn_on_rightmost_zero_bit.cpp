#include <bits/stdc++.h>
using namespace std;

// Turn on the rightmost zero bit.
int turnOnRightmostZeroBit(int n) {
    return n | (n + 1);
}
