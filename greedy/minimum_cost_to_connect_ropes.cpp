#include <bits/stdc++.h>
using namespace std;

// Minimum cost to connect all ropes.
int minCostToConnectRopes(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int rope : ropes)
        pq.push(rope);

    int cost = 0;

    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int combined = first + second;
        cost += combined;

        pq.push(combined);
    }

    return cost;
}
