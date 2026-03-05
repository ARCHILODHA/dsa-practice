#include <bits/stdc++.h>
using namespace std;

/*
Prefix Sum

Prefix sum array stores cumulative sum up to each index.

prefix[i] = arr[0] + arr[1] + ... + arr[i]

Used for:
1. Range sum queries
2. Subarray sum problems
3. Optimization from O(n^2) → O(n)

Range Sum Formula:
sum(l, r) = prefix[r] - prefix[l-1]
*/

vector<int> buildPrefixSum(vector<int>& arr) {
    int n = arr.size();
    vector<int> prefix(n);

    prefix[0] = arr[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

int rangeSum(vector<int>& prefix, int l, int r) {
    if(l == 0) return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main() {
    vector<int> arr = {2, 4, 1, 6, 3};

    vector<int> prefix = buildPrefixSum(arr);

    cout << "Prefix Array: ";
    for(int x : prefix)
        cout << x << " ";

    cout << endl;

    cout << "Sum from index 1 to 3: "
         << rangeSum(prefix, 1, 3) << endl;

    return 0;
}
