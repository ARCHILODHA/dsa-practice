#include <bits/stdc++.h>
using namespace std;

// Convert binary number to Gray code.
int binaryToGray(int n) {
    return n ^ (n >> 1);
}
