#include <bits/stdc++.h>
using namespace std;

// Count how many bits must be changed to convert a to b.
int countBitChanges(int a, int b) {
    int x = a ^ b;
    int count = 0;

    while (x) {
        x &= (x - 1);
        count++;
    }

    return count;
}
