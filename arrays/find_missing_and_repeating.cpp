#include <bits/stdc++.h>
using namespace std;

// Array contains numbers from 1 to n.
// One number is missing and one number appears twice.
//
// Find both numbers.
//
// Uses mathematical equations.
//
// Time: O(n)
// Space: O(1)

pair<int, int> findMissingAndRepeating(vector<int>& nums) {
    long long n = nums.size();

    long long expectedSum = n * (n + 1) / 2;
    long long expectedSquareSum =
        n * (n + 1) * (2 * n + 1) / 6;

    long long actualSum = 0;
    long long actualSquareSum = 0;

    for (long long x : nums) {
        actualSum += x;
        actualSquareSum += x * x;
    }

    // repeating - missing
    long long difference = actualSum - expectedSum;

    // repeating^2 - missing^2
    long long squareDifference =
        actualSquareSum - expectedSquareSum;

    // (R - M)(R + M)
    long long sum = squareDifference / difference;

    long long repeating = (difference + sum) / 2;
    long long missing = repeating - difference;

    return {
        (int)missing,
        (int)repeating
    };
}

int main() {
    vector<int> nums = {1, 2, 2, 4, 5};

    auto result = findMissingAndRepeating(nums);

    cout << "Missing number: "
         << result.first << endl;

    cout << "Repeating number: "
         << result.second << endl;

    return 0;
}
