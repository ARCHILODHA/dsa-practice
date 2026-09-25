#include <bits/stdc++.h>
using namespace std;

// Check whether n is positive without using comparison operators.
bool isPositive(int n) {
    int signBit = (n >> 31) & 1;

    return signBit == 0 && n != 0;
}
