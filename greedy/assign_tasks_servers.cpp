#include <bits/stdc++.h>
using namespace std;

struct Server {
    int weight;
    int index;

    bool operator>(const Server& other) const {
        if (weight == other.weight)
            return index > other.index;
        return weight > other.weight;
    }
};

struct BusyServer {
    long long freeTime;
    int weight;
    int index;

    bool operator>(const BusyServer& other) const {
        if (freeTime == other.freeTime) {
            if (weight == other.weight)
                return index > other.index;
            return weight > other.weight;
        }
        return freeTime > other.freeTime;
    }
};

// Assign tasks to servers based on weight and availability.
vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    priority_queue<Server, vector<Server>, greater<Server>> available;
    priority_queue<BusyServer, vector<BusyServer>, greater<BusyServer>> busy;

    for (int i = 0; i < servers.size(); i++)
        available.push({servers[i], i});

    vector<int> result;

    long long time = 0;

    for (int task = 0; task < tasks.size(); task++) {
        time = max(time, (long long)task);

        while (!busy.empty() && busy.top().freeTime <= time) {
            auto s = busy.top();
            busy.pop();
            available.push({s.weight, s.index});
        }

        if (available.empty()) {
            time = busy.top().freeTime;

            while (!busy.empty() && busy.top().freeTime <= time) {
                auto s = busy.top();
                busy.pop();
                available.push({s.weight, s.index});
            }
        }

        Server server = available.top();
        available.pop();

        result.push_back(server.index);

        busy.push({
            time + tasks[task],
            server.weight,
            server.index
        });
    }

    return result;
}
