#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while(low < high) {
        int mid = low + (high - low) / 2;

        if(nums[mid] < nums[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    vector<int> nums = {1,2,3,1};

    cout << "Peak Index: " << findPeakElement(nums);

    return 0;
}
