#include <bits/stdc++.h>
using namespace std;

// Calculate trapped rainwater using two pointers.
//
// Time: O(n)
// Space: O(1)

int trap(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {

            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                water += leftMax - height[left];
            }

            left++;
        }
        else {

            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }

            right--;
        }
    }

    return water;
}

int main() {
    vector<int> height = {
        4, 2, 0, 3, 2, 5
    };

    cout << "Trapped rainwater: "
         << trap(height) << endl;

    return 0;
}
