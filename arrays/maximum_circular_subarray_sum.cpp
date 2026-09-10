#include <bits/stdc++.h>
using namespace std;

// Maximum subarray sum in a circular array.

int kadane(vector<int>& arr) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        current = max(arr[i], current + arr[i]);
        best = max(best, current);
    }

    return best;
}

int maxCircularSum(vector<int>& arr) {
    int normalMax = kadane(arr);

    // If all values are negative.
    if (normalMax < 0) {
        return normalMax;
    }

    int totalSum = 0;
    for (int x : arr) {
        totalSum += x;
    }

    // Find minimum subarray using Kadane.
    int currentMin = arr[0];
    int minSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        currentMin = min(arr[i], currentMin + arr[i]);
        minSum = min(minSum, currentMin);
    }

    int circularMax = totalSum - minSum;

    return max(normalMax, circularMax);
}

int main() {
    vector<int> arr = {5, -3, 5};

    cout << "Maximum circular subarray sum: "
         << maxCircularSum(arr) << endl;

    return 0;
}
