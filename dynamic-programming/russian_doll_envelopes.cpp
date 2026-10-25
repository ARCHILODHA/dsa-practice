// Problem: Russian Doll Envelopes
// Approach: Sorting + Binary Search + LIS
// Time Complexity: O(n log n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes) {
    sort(envelopes.begin(), envelopes.end(),
         [](const vector<int>& a, const vector<int>& b) {
             if (a[0] == b[0])
                 return a[1] > b[1];

             return a[0] < b[0];
         });

    vector<int> lis;

    for (const auto& envelope : envelopes) {
        int height = envelope[1];

        auto it = lower_bound(
            lis.begin(), lis.end(), height
        );

        if (it == lis.end()) {
            lis.push_back(height);
        } else {
            *it = height;
        }
    }

    return lis.size();
}

int main() {
    vector<vector<int>> envelopes = {
        {5, 4},
        {6, 4},
        {6, 7},
        {2, 3}
    };

    cout << "Maximum Nested Envelopes: "
         << maxEnvelopes(envelopes) << endl;

    return 0;
}
