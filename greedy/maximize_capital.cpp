#include <bits/stdc++.h>
using namespace std;

// Maximize capital by selecting at most k profitable projects.
int maximizeCapital(int k, int initialCapital,
                    vector<int>& profits,
                    vector<int>& capital) {
    vector<pair<int, int>> projects;

    for (int i = 0; i < profits.size(); i++)
        projects.push_back({capital[i], profits[i]});

    sort(projects.begin(), projects.end());

    priority_queue<int> maxProfit;

    int index = 0;
    int currentCapital = initialCapital;

    for (int i = 0; i < k; i++) {
        while (index < projects.size() &&
               projects[index].first <= currentCapital) {
            maxProfit.push(projects[index].second);
            index++;
        }

        if (maxProfit.empty())
            break;

        currentCapital += maxProfit.top();
        maxProfit.pop();
    }

    return currentCapital;
}
