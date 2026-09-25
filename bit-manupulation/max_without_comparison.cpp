#include <bits/stdc++.h>
using namespace std;

// Find maximum of two integers using bit manipulation.
int maximum(int a, int b) {
    int diff = a - b;
    int mask = diff >> 31;

    return a - (diff & mask);
}
