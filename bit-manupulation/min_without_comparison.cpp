#include <bits/stdc++.h>
using namespace std;

// Find minimum of two integers using bit manipulation.
int minimum(int a, int b) {
    int diff = a - b;
    int mask = diff >> 31;

    return b + (diff & mask);
}
