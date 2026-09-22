#include <bits/stdc++.h>
using namespace std;

// Assign bikes to workers using minimum Manhattan distance.
vector<pair<int, int>> assignBikes(vector<pair<int, int>>& workers,
                                   vector<pair<int, int>>& bikes) {
    vector<tuple<int, int, int>> pairs;

    for (int i = 0; i < workers.size(); i++) {
        for (int j = 0; j < bikes.size(); j++) {
            int dist = abs(workers[i].first - bikes[j].first) +
                       abs(workers[i].second - bikes[j].second);
            pairs.push_back({dist, i, j});
        }
    }

    sort(pairs.begin(), pairs.end());

    vector<bool> workerUsed(workers.size(), false);
    vector<bool> bikeUsed(bikes.size(), false);
    vector<pair<int, int>> result(workers.size());

    for (auto [dist, worker, bike] : pairs) {
        if (!workerUsed[worker] && !bikeUsed[bike]) {
            result[worker] = bikes[bike];
            workerUsed[worker] = true;
            bikeUsed[bike] = true;
        }
    }

    return result;
}
