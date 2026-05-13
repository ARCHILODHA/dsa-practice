#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls, int cows, int dist) {
    int count = 1, last = stalls[0];

    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
    }

    return count >= cows;
}

int aggressiveCows(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());

    int low = 1;
    int high = stalls.back() - stalls[0];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(stalls, cows, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }

    return high;
}
