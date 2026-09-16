#include <bits/stdc++.h>
using namespace std;

// Find the median of two sorted arrays.
//
// Uses binary search partitioning.
//
// Time: O(log(min(n, m)))
// Space: O(1)

double findMedianSortedArrays(
    vector<int>& a,
    vector<int>& b
) {
    if (a.size() > b.size()) {
        return findMedianSortedArrays(b, a);
    }

    int n = a.size();
    int m = b.size();

    int low = 0;
    int high = n;

    while (low <= high) {

        int cutA = low + (high - low) / 2;
        int cutB = (n + m + 1) / 2 - cutA;

        int leftA =
            (cutA == 0) ? INT_MIN : a[cutA - 1];

        int rightA =
            (cutA == n) ? INT_MAX : a[cutA];

        int leftB =
            (cutB == 0) ? INT_MIN : b[cutB - 1];

        int rightB =
            (cutB == m) ? INT_MAX : b[cutB];

        if (leftA <= rightB &&
            leftB <= rightA) {

            if ((n + m) % 2 == 0) {
                return (
                    max(leftA, leftB) +
                    min(rightA, rightB)
                ) / 2.0;
            }

            return max(leftA, leftB);
        }

        if (leftA > rightB) {
            high = cutA - 1;
        }
        else {
            low = cutA + 1;
        }
    }

    return 0.0;
}

int main() {
    vector<int> a = {1, 3};
    vector<int> b = {2};

    cout << "Median: "
         << findMedianSortedArrays(a, b)
         << endl;

    return 0;
}
