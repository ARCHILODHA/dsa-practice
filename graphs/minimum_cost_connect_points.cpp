#include <bits/stdc++.h>
using namespace std;

// Minimum cost to connect all points.
// Cost between two points = Manhattan distance.
int minCostConnectPoints(
    vector<vector<int>>& points
) {
    int n = points.size();

    vector<int> minDist(n, INT_MAX);
    vector<int> used(n, 0);

    minDist[0] = 0;

    int totalCost = 0;

    for (int count = 0; count < n; ++count) {
        int node = -1;

        for (int i = 0; i < n; ++i) {
            if (!used[i] &&
                (node == -1 ||
                 minDist[i] < minDist[node])) {
                node = i;
            }
        }

        used[node] = 1;
        totalCost += minDist[node];

        for (int next = 0; next < n; ++next) {
            if (!used[next]) {
                int cost =
                    abs(points[node][0] - points[next][0]) +
                    abs(points[node][1] - points[next][1]);

                minDist[next] =
                    min(minDist[next], cost);
            }
        }
    }

    return totalCost;
}

int main() {
    vector<vector<int>> points = {
        {0, 0},
        {2, 2},
        {3, 10},
        {5, 2},
        {7, 0}
    };

    cout << "Minimum connection cost = "
         << minCostConnectPoints(points)
         << '\n';

    return 0;
}
