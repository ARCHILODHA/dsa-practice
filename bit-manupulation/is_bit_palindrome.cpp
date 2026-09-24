#include <bits/stdc++.h>
using namespace std;

// Check whether the binary representation of n is a palindrome.
bool isBitPalindrome(unsigned int n) {
    int left = 31;

    while (left >= 0 && ((n >> left) & 1) == 0)
        left--;

    int right = 0;

    while (right < left) {
        int leftBit = (n >> left) & 1;
        int rightBit = (n >> right) & 1;

        if (leftBit != rightBit)
            return false;

        left--;
        right++;
    }

    return true;
}
