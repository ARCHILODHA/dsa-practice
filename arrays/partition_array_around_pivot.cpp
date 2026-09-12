#include <bits/stdc++.h>
using namespace std;

// Rearrange the array so that:
// elements < pivot come first,
// elements == pivot come next,
// elements > pivot come last.
//
// This is the Dutch National Flag pattern.

void partitionAroundPivot(vector<int>& nums, int pivot) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high) {
        if (nums[mid] < pivot) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == pivot) {
            mid++;
        }
        else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main() {
    vector<int> nums = {9, 12, 3, 5, 14, 10, 10};
    int pivot = 10;

    partitionAroundPivot(nums, pivot);

    cout << "Partitioned array: ";

    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
