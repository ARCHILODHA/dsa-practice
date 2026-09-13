#include <bits/stdc++.h>
using namespace std;

// Distribute candies such that:
// 1. Every child gets at least one candy.
// 2. A child with a higher rating than a neighbor
//    gets more candies.
//
// Time: O(n)
// Space: O(n)

int candy(vector<int>& ratings) {
    int n = ratings.size();

    vector<int> candies(n, 1);

    // Left to right.
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Right to left.
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i],
                             candies[i + 1] + 1);
        }
    }

    int total = 0;

    for (int x : candies) {
        total += x;
    }

    return total;
}

int main() {
    vector<int> ratings = {1, 0, 2};

    cout << "Minimum candies required: "
         << candy(ratings) << endl;

    return 0;
}
