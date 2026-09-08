#include <bits/stdc++.h>
using namespace std;

// Maximum Product Subarray
// Time: O(n)
// Space: O(1)

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &x : arr)
        cin >> x;

    int currentMax = arr[0];
    int currentMin = arr[0];
    int answer = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < 0)
            swap(currentMax, currentMin);

        currentMax = max(arr[i], currentMax * arr[i]);
        currentMin = min(arr[i], currentMin * arr[i]);

        answer = max(answer, currentMax);
    }

    cout << "Maximum product: " << answer << endl;

    return 0;
}
