#include <bits/stdc++.h>
using namespace std;

// Convert Gray code to binary.
int grayToBinary(int gray) {
    int binary = gray;

    while (gray >>= 1)
        binary ^= gray;

    return binary;
}
