#include <bits/stdc++.h>
using namespace std;

// Place k cows in stalls such that the minimum distance
// between any two cows is maximized.
//
// Binary Search on Answer.
//
// Time: O(n log n + n log(maxDistance))
// Space: O(1)

bool canPlace(vector<int>& stalls,
              int cows,
              int minimumDistance) {

    int placed = 1;
    int lastPosition = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastPosition >= minimumDistance) {
            placed++;
            lastPosition = stalls[i];

            if (placed == cows) {
                return true;
            }
        }
    }

    return false;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls.front();

    int answer = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, cows, mid)) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    vector<int> stalls = {
        1, 2, 4, 8, 9
    };

    int cows = 3;

    cout << "Maximum minimum distance: "
         << aggressiveCows(stalls, cows)
         << endl;

    return 0;
}
