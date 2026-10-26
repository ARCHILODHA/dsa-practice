#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrivalTime(n);

        for (int i = 0; i < n; i++) {
            arrivalTime[i] =
                (double)dist[i] / speed[i];
        }

        sort(arrivalTime.begin(), arrivalTime.end());

        for (int i = 0; i < n; i++) {
            if (arrivalTime[i] <= i) {
                return i;
            }
        }

        return n;
    }
};
