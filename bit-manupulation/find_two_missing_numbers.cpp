#include <bits/stdc++.h>
using namespace std;

// Array contains numbers from 1 to n with two numbers missing.
vector<int> findTwoMissingNumbers(vector<int>& nums, int n) {
    int xr = 0;

    for (int i = 1; i <= n; i++)
        xr ^= i;

    for (int num : nums)
        xr ^= num;

    int rightmostBit = xr & (-xr);

    int a = 0;
    int b = 0;

    for (int i = 1; i <= n; i++) {
        if (i & rightmostBit)
            a ^= i;
        else
            b ^= i;
    }

    for (int num : nums) {
        if (num & rightmostBit)
            a ^= num;
        else
            b ^= num;
    }

    return {a, b};
}
