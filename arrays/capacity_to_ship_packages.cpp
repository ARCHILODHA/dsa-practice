#include <bits/stdc++.h>
using namespace std;

// Find the minimum ship capacity needed to ship
// all packages within a given number of days.
//
// Binary Search on Answer.
//
// Time: O(n log(sum))
// Space: O(1)

bool canShip(vector<int>& weights,
             int days,
             long long capacity) {

    int requiredDays = 1;
    long long currentWeight = 0;

    for (int weight : weights) {

        if (currentWeight + weight <= capacity) {
            currentWeight += weight;
        }
        else {
            requiredDays++;
            currentWeight = weight;
        }
    }

    return requiredDays <= days;
}

long long shipWithinDays(
    vector<int>& weights,
    int days
) {
    long long low =
        *max_element(weights.begin(), weights.end());

    long long high =
        accumulate(weights.begin(),
                   weights.end(),
                   0LL);

    long long answer = high;

    while (low <= high) {

        long long mid =
            low + (high - low) / 2;

        if (canShip(weights, days, mid)) {
            answer = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> weights = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    int days = 5;

    cout << "Minimum capacity: "
         << shipWithinDays(weights, days)
         << endl;

    return 0;
}
