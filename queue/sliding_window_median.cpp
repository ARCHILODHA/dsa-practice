#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        vector<double> result;

        auto getMedian = [&]() -> double {
            auto mid = next(window.begin(), k / 2);

            if (k % 2 == 1) {
                return *mid;
            }

            auto left = prev(mid);

            return ((double)*left + *mid) / 2.0;
        };

        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);

            if (window.size() > k) {
                auto it = window.find(nums[i - k]);
                window.erase(it);
            }

            if (window.size() == k) {
                result.push_back(getMedian());
            }
        }

        return result;
    }
};
