#include <bits/stdc++.h>
using namespace std;

// Find the first and last position of a target
// in a sorted array.
//
// Time: O(log n)
// Space: O(1)

int findFirst(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            answer = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}

int findLast(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int answer = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            answer = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}

vector<int> searchRange(vector<int>& nums, int target) {
    return {
        findFirst(nums, target),
        findLast(nums, target)
    };
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> result = searchRange(nums, target);

    cout << "First position: " << result[0] << endl;
    cout << "Last position: " << result[1] << endl;

    return 0;
}
