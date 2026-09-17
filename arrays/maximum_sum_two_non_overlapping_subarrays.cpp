#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum of two non-overlapping
// subarrays with lengths firstLen and secondLen.
//
// Uses prefix sums.
//
// Time: O(n)
// Space: O(n)

int maxSumTwoNoOverlap(
    vector<int>& nums,
    int firstLen,
    int secondLen
) {
    int n = nums.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] =
            prefix[i] + nums[i];
    }

    int answer = 0;

    int bestFirst = 0;

    for (int i = firstLen + secondLen;
         i <= n;
         i++) {

        // First subarray ends before
        // the second subarray starts.
        bestFirst = max(
            bestFirst,
            prefix[i - secondLen] -
            prefix[i - secondLen - firstLen]
        );

        int secondSum =
            prefix[i] -
            prefix[i - secondLen];

        answer = max(
            answer,
            bestFirst + secondSum
        );
    }

    // Swap the lengths to consider
    // the opposite ordering.
    bestFirst = 0;

    for (int i = secondLen + firstLen;
         i <= n;
         i++) {

        bestFirst = max(
            bestFirst,
            prefix[i - firstLen] -
            prefix[i - firstLen - secondLen]
        );

        int firstSum =
            prefix[i] -
            prefix[i - firstLen];

        answer = max(
            answer,
            bestFirst + firstSum
        );
    }

    return answer;
}

int main() {
    vector<int> nums = {
        0, 6, 5, 2, 2, 5, 1, 9, 4
    };

    int firstLen = 1;
    int secondLen = 2;

    cout << "Maximum sum: "
         << maxSumTwoNoOverlap(
                nums,
                firstLen,
                secondLen
            )
         << endl;

    return 0;
}
