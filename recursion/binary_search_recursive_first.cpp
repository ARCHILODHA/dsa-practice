#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(vector<int>& arr, int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] >= target) {
        int left = firstOccurrence(arr, low, mid - 1, target);

        if (left != -1) return left;

        return arr[mid] == target ? mid : -1;
    }

    return firstOccurrence(arr, mid + 1, high, target);
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    cout << firstOccurrence(arr, 0, n - 1, target);

    return 0;
}
