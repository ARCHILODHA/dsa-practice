#include <bits/stdc++.h>
using namespace std;

// Find the maximum product of any three numbers.
//
// Important observation:
// The answer can be either:
// largest * secondLargest * thirdLargest
// OR
// smallest * secondSmallest * largest
//
// Time: O(n)
// Space: O(1)

long long maximumProduct(vector<int>& nums) {
    long long largest = LLONG_MIN;
    long long secondLargest = LLONG_MIN;
    long long thirdLargest = LLONG_MIN;

    long long smallest = LLONG_MAX;
    long long secondSmallest = LLONG_MAX;

    for (long long x : nums) {

        if (x >= largest) {
            thirdLargest = secondLargest;
            secondLargest = largest;
            largest = x;
        }
        else if (x >= secondLargest) {
            thirdLargest = secondLargest;
            secondLargest = x;
        }
        else if (x > thirdLargest) {
            thirdLargest = x;
        }

        if (x <= smallest) {
            secondSmallest = smallest;
            smallest = x;
        }
        else if (x < secondSmallest) {
            secondSmallest = x;
        }
    }

    long long option1 =
        largest * secondLargest * thirdLargest;

    long long option2 =
        smallest * secondSmallest * largest;

    return max(option1, option2);
}

int main() {
    vector<int> nums = {
        -10, -10, 5, 2
    };

    cout << "Maximum product of three: "
         << maximumProduct(nums)
         << endl;

    return 0;
}
