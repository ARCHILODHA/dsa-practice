#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> merged;

    merged.insert(merged.end(), a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());

    sort(merged.begin(), merged.end());

    int n = merged.size();

    if (n % 2)
        return merged[n / 2];

    return (merged[n / 2] + merged[n / 2 - 1]) / 2.0;
}
