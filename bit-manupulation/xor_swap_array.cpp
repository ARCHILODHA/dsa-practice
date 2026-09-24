#include <bits/stdc++.h>
using namespace std;

// Reverse an array using XOR swapping.
void reverseUsingXOR(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        arr[left] ^= arr[right];
        arr[right] ^= arr[left];
        arr[left] ^= arr[right];

        left++;
        right--;
    }
}
