#include <bits/stdc++.h>
using namespace std;

// Find maximum j - i such that nums[i] <= nums[j].

int maximumDistance(vector<int>& nums) {
    int n = nums.size();

    vector<int> prefixMin(n);
    vector<int> suffixMax(n);

    prefixMin[0] = nums[0];

    for (int i = 1; i < n; i++) {
        prefixMin[i] = min(prefixMin[i - 1], nums[i]);
    }

    suffixMax[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i + 1], nums[i]);
    }

    int i = 0;
    int j = 0;
    int answer = 0;

    while (i < n && j < n) {
        if (prefixMin[i] <= suffixMax[j]) {
            answer = max(answer, j - i);
            j++;
        } else {
            i++;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {34, 8, 10, 3, 2, 80, 30, 33, 1};

    cout << "Maximum distance: "
         << maximumDistance(nums) << endl;

    return 0;
}
