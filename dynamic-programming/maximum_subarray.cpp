#include <bits/stdc++.h>
using namespace std;

// Maximum Subarray - Kadane's Algorithm
// Time: O(n)
// Space: O(1)

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &x : arr)
        cin >> x;

    int current = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        current = max(arr[i], current + arr[i]);
        maximum = max(maximum, current);
    }

    cout << "Maximum subarray sum: " << maximum << endl;

    return 0;
}
