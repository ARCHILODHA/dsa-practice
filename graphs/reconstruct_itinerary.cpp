#include <bits/stdc++.h>
using namespace std;

// Reconstruct itinerary using all tickets exactly once.
// Hierholzer's algorithm is used for the Eulerian path.
class Itinerary {
    unordered_map<string, priority_queue<
        string,
        vector<string>,
        greater<string>
    >> graph;

    vector<string> route;

    void dfs(const string& airport) {
        auto& destinations = graph[airport];

        while (!destinations.empty()) {
            string next = destinations.top();
            destinations.pop();

            dfs(next);
        }

        route.push_back(airport);
    }

public:
    vector<string> findRoute(
        vector<vector<string>>& tickets
    ) {
        for (auto& ticket : tickets) {
            graph[ticket[0]].push(ticket[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());

        return route;
    }
};

int main() {
    vector<vector<string>> tickets = {
        {"MUC", "LHR"},
        {"JFK", "MUC"},
        {"SFO", "SJC"},
        {"LHR", "SFO"}
    };

    Itinerary solver;

    vector<string> route =
        solver.findRoute(tickets);

    cout << "Itinerary: ";

    for (const string& airport : route)
        cout << airport << " ";

    cout << '\n';

    return 0;
}
