#include <bits/stdc++.h>
using namespace std;

// Minimum number of refueling stops needed to reach target.
int minRefuelStops(int target, int startFuel,
                   vector<vector<int>>& stations) {
    priority_queue<int> fuels;

    long long fuel = startFuel;
    int stops = 0;
    int index = 0;

    while (fuel < target) {
        while (index < stations.size() &&
               stations[index][0] <= fuel) {
            fuels.push(stations[index][1]);
            index++;
        }

        if (fuels.empty())
            return -1;

        fuel += fuels.top();
        fuels.pop();
        stops++;
    }

    return stops;
}
