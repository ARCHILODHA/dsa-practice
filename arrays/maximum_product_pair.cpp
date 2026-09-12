#include <bits/stdc++.h>
using namespace std;

// Find the maximum product of any two elements.

long long maximumProductPair(vector<int>& nums) {
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int x : nums) {
        if (x >= largest) {
            secondLargest = largest;
            largest = x;
        }
        else if (x > secondLargest) {
            secondLargest = x;
        }

        if (x <= smallest) {
            secondSmallest = smallest;
            smallest = x;
        }
        else if (x < secondSmallest) {
            secondSmallest = x;
        }
    }

    return max(
        1LL * largest * secondLargest,
        1LL * smallest * secondSmallest
    );
}

int main() {
    vector<int> nums = {-10, -3, 5, 6, -2};

    cout << "Maximum product pair: "
         << maximumProductPair(nums) << endl;

    return 0;
}
