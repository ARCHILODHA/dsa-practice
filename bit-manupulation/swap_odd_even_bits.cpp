#include <bits/stdc++.h>
using namespace std;

// Swap odd and even positioned bits of a 32-bit integer.
unsigned int swapOddEvenBits(unsigned int n) {
    unsigned int evenBits = n & 0xAAAAAAAA;
    unsigned int oddBits = n & 0x55555555;

    evenBits >>= 1;
    oddBits <<= 1;

    return evenBits | oddBits;
}
