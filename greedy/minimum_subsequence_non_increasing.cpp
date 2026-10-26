#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int selectedSum = 0;

        vector<int> result;

        for (int num : nums) {
            result.push_back(num);
            selectedSum += num;

            if (selectedSum > totalSum - selectedSum) {
                break;
            }
        }

        return result;
    }
};
