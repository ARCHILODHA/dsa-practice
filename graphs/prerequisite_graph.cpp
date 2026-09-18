#include <bits/stdc++.h>
using namespace std;

// Determines whether all courses can be completed.
// course <- prerequisite
bool canFinish(
    int n,
    vector<pair<int, int>>& prerequisites
) {
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (auto [course, prerequisite] : prerequisites) {
        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int completed = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        completed++;

        for (int next : adj[node]) {
            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    return completed == n;
}

int main() {
    int courses = 4;

    vector<pair<int, int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    cout << (canFinish(courses, prerequisites)
        ? "All courses can be completed"
        : "Prerequisite cycle exists") << '\n';

    return 0;
}
