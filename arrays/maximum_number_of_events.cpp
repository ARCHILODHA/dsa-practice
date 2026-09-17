#include <bits/stdc++.h>
using namespace std;

// Attend the maximum number of events.
// Each event has a start and end day.
//
// Greedy + Min Heap.
//
// Time: O(n log n)
// Space: O(n)

int maxEvents(vector<vector<int>>& events) {
    sort(events.begin(), events.end());

    priority_queue<int,
                   vector<int>,
                   greater<int>> minHeap;

    int n = events.size();
    int index = 0;
    int day = 0;
    int answer = 0;

    while (index < n || !minHeap.empty()) {

        if (minHeap.empty()) {
            day = max(day, events[index][0]);
        }

        // Add all events starting today.
        while (index < n &&
               events[index][0] <= day) {

            minHeap.push(events[index][1]);
            index++;
        }

        // Remove expired events.
        while (!minHeap.empty() &&
               minHeap.top() < day) {

            minHeap.pop();
        }

        // Attend the event ending earliest.
        if (!minHeap.empty()) {
            minHeap.pop();
            answer++;
            day++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> events = {
        {1, 2},
        {2, 3},
        {3, 4},
        {1, 2}
    };

    cout << "Maximum events: "
         << maxEvents(events)
         << endl;

    return 0;
}
