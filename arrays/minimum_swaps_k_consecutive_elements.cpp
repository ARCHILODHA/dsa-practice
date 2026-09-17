#include <bits/stdc++.h>
using namespace std;

// Given positions of elements, find the minimum number
// of adjacent swaps required to make k elements consecutive.
//
// Uses sorted positions and a sliding window.
//
// Time: O(n log n)
// Space: O(n)

long long minimumSwaps(
    vector<int>& positions,
    int k
) {
    sort(positions.begin(), positions.end());

    int n = positions.size();

    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] =
            prefix[i] + positions[i];
    }

    long long answer = LLONG_MAX;

    for (int i = 0; i + k <= n; i++) {

        int mid = i + k / 2;

        long long median =
            positions[mid];

        long long leftCount =
            mid - i;

        long long leftSum =
            prefix[mid] - prefix[i];

        long long rightSum =
            prefix[i + k] - prefix[mid + 1];

        long long rightCount =
            i + k - mid - 1;

        long long cost =
            median * leftCount - leftSum;

        cost +=
            rightSum -
            median * rightCount;

        // Elements on the right need to account
        // for the gaps caused by consecutive positions.
        long long targetStart =
            median - (mid - i);

        long long adjustment =
            (long long)(mid - i) *
            (mid - i + 1) / 2;

        cost -= adjustment;

        long long rightElements =
            i + k - mid - 1;

        long long rightAdjustment =
            rightElements *
            (rightElements + 1) / 2;

        cost -= rightAdjustment;

        answer = min(answer, cost);
    }

    return answer;
}

int main() {
    vector<int> positions = {
        1, 2, 3, 7, 8, 9
    };

    int k = 3;

    cout << "Minimum swaps: "
         << minimumSwaps(positions, k)
         << endl;

    return 0;
}
