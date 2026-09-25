#include <bits/stdc++.h>
using namespace std;

// Find absolute value using bit manipulation.
int absoluteValue(int n) {
    int mask = n >> 31;

    return (n ^ mask) - mask;
}
