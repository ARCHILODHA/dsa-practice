#include <bits/stdc++.h>
using namespace std;

struct Worker {
    double ratio;
    int quality;
};

// Minimum cost to hire exactly k workers.
double minCostToHireWorkers(vector<int>& quality,
                            vector<int>& wage,
                            int k) {
    vector<Worker> workers;

    for (int i = 0; i < quality.size(); i++) {
        workers.push_back({
            (double)wage[i] / quality[i],
            quality[i]
        });
    }

    sort(workers.begin(), workers.end(),
         [](const Worker& a, const Worker& b) {
             return a.ratio < b.ratio;
         });

    priority_queue<int> maxHeap;
    int qualitySum = 0;
    double answer = DBL_MAX;

    for (auto& worker : workers) {
        maxHeap.push(worker.quality);
        qualitySum += worker.quality;

        if (maxHeap.size() > k) {
            qualitySum -= maxHeap.top();
            maxHeap.pop();
        }

        if (maxHeap.size() == k) {
            answer = min(
                answer,
                qualitySum * worker.ratio
            );
        }
    }

    return answer;
}
