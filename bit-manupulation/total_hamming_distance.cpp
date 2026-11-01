#include <bits/stdc++.h>
using namespace std;

long long totalHammingDistance(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();

    for (int bit = 0; bit < 32; bit++) {
        long long ones = 0;

        for (int num : nums) {
            if ((static_cast<unsigned int>(num) >> bit) & 1U) {
                ones++;
            }
        }

        long long zeros = n - ones;
        ans += ones * zeros;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << totalHammingDistance(nums);

    return 0;
}
