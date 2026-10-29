#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
private:
    deque<int> requests;

public:
    RecentCounter() {}

    int ping(int t) {
        requests.push_back(t);

        while (!requests.empty() &&
               requests.front() < t - 3000) {
            requests.pop_front();
        }

        return requests.size();
    }
};
