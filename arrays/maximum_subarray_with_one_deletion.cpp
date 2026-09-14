#include <bits/stdc++.h>
using namespace std;

// Find the maximum subarray sum when you are allowed
// to delete at most one element.
//
// Time: O(n)
// Space: O(1)

int maximumSum(vector<int>& arr) {
    int keep = arr[0];
    int deleted = INT_MIN;

    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        int previousKeep = keep;
        int previousDeleted = deleted;

        keep = max(arr[i], previousKeep + arr[i]);

        deleted = max(
            previousKeep,
            previousDeleted + arr[i]
        );

        answer = max({answer, keep, deleted});
    }

    return answer;
}

int main() {
    vector<int> arr = {1, -2, 0, 3};

    cout << "Maximum sum with one deletion: "
         << maximumSum(arr) << endl;

    return 0;
}
