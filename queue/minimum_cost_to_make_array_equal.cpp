#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<int, int>> elements;

        for (int i = 0; i < n; i++) {
            elements.push_back({nums[i], cost[i]});
        }

        sort(elements.begin(), elements.end());

        long long totalCost = 0;
        long long totalWeight = 0;

        for (auto& element : elements) {
            totalWeight += element.second;
        }

        long long currentWeight = 0;
        int target = elements[0].first;

        for (auto& element : elements) {
            currentWeight += element.second;

            if (currentWeight * 2 >= totalWeight) {
                target = element.first;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            totalCost += 1LL * abs(nums[i] - target) * cost[i];
        }

        return totalCost;
    }
};
