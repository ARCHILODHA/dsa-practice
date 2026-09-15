#include <bits/stdc++.h>
using namespace std;

// Find the kth smallest element from two sorted arrays.
//
// Uses binary search on the smaller array.
//
// Time: O(log(min(n, m)))
// Space: O(1)

int kthElement(vector<int>& a,
               vector<int>& b,
               int k) {

    if (a.size() > b.size()) {
        return kthElement(b, a, k);
    }

    int n = a.size();
    int m = b.size();

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high) {
        int cutA = low + (high - low) / 2;
        int cutB = k - cutA;

        int leftA =
            (cutA == 0) ? INT_MIN : a[cutA - 1];

        int leftB =
            (cutB == 0) ? INT_MIN : b[cutB - 1];

        int rightA =
            (cutA == n) ? INT_MAX : a[cutA];

        int rightB =
            (cutB == m) ? INT_MAX : b[cutB];

        if (leftA <= rightB &&
            leftB <= rightA) {

            return max(leftA, leftB);
        }

        if (leftA > rightB) {
            high = cutA - 1;
        } else {
            low = cutA + 1;
        }
    }

    return -1;
}

int main() {
    vector<int> a = {
        2, 3, 6, 7, 9
    };

    vector<int> b = {
        1, 4, 8, 10
    };

    int k = 5;

    cout << "Kth element: "
         << kthElement(a, b, k)
         << endl;

    return 0;
}
