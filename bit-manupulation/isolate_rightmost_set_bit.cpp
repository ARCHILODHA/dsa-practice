#include <bits/stdc++.h>
using namespace std;

// Returns a number containing only the rightmost set bit.
int isolateRightmostSetBit(int n) {
    return n & (-n);
}
