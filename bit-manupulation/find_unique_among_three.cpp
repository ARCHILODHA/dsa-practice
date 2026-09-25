#include <bits/stdc++.h>
using namespace std;

// Every number appears three times except one.
// Find the number that appears only once.
int findUnique(vector<int>& nums) {
    int ones = 0;
    int twos = 0;

    for (int num : nums) {
        ones = (ones ^ num) & ~twos;
        twos = (twos ^ num) & ~ones;
    }

    return ones;
}
