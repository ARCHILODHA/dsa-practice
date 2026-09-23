#include <bits/stdc++.h>
using namespace std;

// Select k numbers to maximize their product.
long long maximumProduct(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    long long product = 1;
    int left = 0;
    int right = nums.size() - 1;

    while (k > 0) {
        if (k >= 2 && left + 1 <= right) {
            long long leftProduct =
                1LL * nums[left] * nums[left + 1];

            long long rightProduct =
                1LL * nums[right] * nums[right - 1];

            if (leftProduct > rightProduct) {
                product *= leftProduct;
                left += 2;
            } else {
                product *= rightProduct;
                right -= 2;
            }

            k -= 2;
        } else {
            product *= nums[right--];
            k--;
        }
    }

    return product;
}
