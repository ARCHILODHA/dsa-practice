#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        int cnt = 0;
        int end = INT_MIN;

        for (auto &it : intervals) {
            if (it[0] >= end) {
                cnt++;
                end = it[1];
            }
        }

        return intervals.size() - cnt;
    }
};
