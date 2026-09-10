#include <bits/stdc++.h>
using namespace std;

// Find a subarray with a given sum.
// Works efficiently when all numbers are non-negative.

vector<int> subarrayWithGivenSum(vector<int>& arr, int target) {
    int left = 0;
    long long sum = 0;

    for (int right = 0; right < arr.size(); right++) {
        sum += arr[right];

        while (sum > target && left <= right) {
            sum -= arr[left++];
        }

        if (sum == target) {
            return {left, right};
        }
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {1, 4, 20, 3, 10, 5};
    int target = 33;

    vector<int> result = subarrayWithGivenSum(arr, target);

    if (result[0] != -1) {
        cout << "Subarray found from index "
             << result[0] << " to " << result[1] << endl;
    } else {
        cout << "Subarray not found" << endl;
    }

    return 0;
}
