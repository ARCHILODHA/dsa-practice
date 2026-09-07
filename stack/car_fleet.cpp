#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Each car has a position and speed.
// Cars moving toward the same destination form a fleet
// when a faster car catches a slower car.
int carFleet(
    int target,
    vector<int>& position,
    vector<int>& speed
) {
    int n = position.size();

    vector<pair<int, double>> cars;

    // Store position and time required to reach target.
    for (int i = 0; i < n; i++) {
        double time =
            (double)(target - position[i]) / speed[i];

        cars.push_back({position[i], time});
    }

    // Process cars from closest to target to farthest.
    sort(cars.begin(), cars.end());

    stack<double> fleets;

    for (int i = n - 1; i >= 0; i--) {

        double currentTime = cars[i].second;

        // If current car takes longer, it cannot catch
        // the fleet ahead, so it forms a new fleet.
        if (fleets.empty() ||
            currentTime > fleets.top()) {

            fleets.push(currentTime);
        }
    }

    return fleets.size();
}

int main() {
    int target = 12;

    vector<int> position = {
        10, 8, 0, 5, 3
    };

    vector<int> speed = {
        2, 4, 1, 1, 3
    };

    cout << "Number of car fleets: "
         << carFleet(target, position, speed)
         << endl;

    return 0;
}
