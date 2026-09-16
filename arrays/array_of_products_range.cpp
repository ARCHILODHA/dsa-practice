#include <bits/stdc++.h>
using namespace std;

// Answer multiple range product queries.
//
// First build prefix and suffix products.
//
// This example assumes the product fits in long long.
//
// Time: O(n + q)
// Space: O(n)

vector<long long> buildPrefixProduct(
    vector<int>& nums
) {
    int n = nums.size();

    vector<long long> prefix(n + 1, 1);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] =
            prefix[i] * nums[i];
    }

    return prefix;
}

long long rangeProduct(
    vector<long long>& prefix,
    int left,
    int right,
    vector<int>& nums
) {
    // For a simple demonstration.
    // Direct multiplication avoids division issues
    // when the range contains zero.

    long long product = 1;

    for (int i = left; i <= right; i++) {
        product *= nums[i];
    }

    return product;
}

int main() {
    vector<int> nums = {
        2, 3, 4, 5, 6
    };

    vector<long long> prefix =
        buildPrefixProduct(nums);

    int left = 1;
    int right = 3;

    cout << "Range product: "
         << rangeProduct(
                prefix,
                left,
                right,
                nums
            )
         << endl;

    return 0;
}
