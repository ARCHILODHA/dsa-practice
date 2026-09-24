#include <bits/stdc++.h>
using namespace std;

// Count the number of set bits in n.
int countSetBits(int n) {
    int count = 0;

    while (n > 0) {
        n &= (n - 1);
        count++;
    }

    return count;
}
