#include <bits/stdc++.h>
using namespace std;

// Find the minimum number of railway platforms required
// so that no train has to wait.
//
// Time: O(n log n)
// Space: O(n)

int findMinimumPlatforms(vector<int>& arrival,
                         vector<int>& departure) {

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int n = arrival.size();

    int i = 0;
    int j = 0;

    int platforms = 0;
    int answer = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            answer = max(answer, platforms);
            i++;
        }
        else {
            platforms--;
            j++;
        }
    }

    return answer;
}

int main() {
    vector<int> arrival = {
        900, 940, 950, 1100, 1500, 1800
    };

    vector<int> departure = {
        910, 1200, 1120, 1130, 1900, 2000
    };

    cout << "Minimum platforms required: "
         << findMinimumPlatforms(arrival, departure)
         << endl;

    return 0;
}
