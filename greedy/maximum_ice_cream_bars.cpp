#include <bits/stdc++.h>
using namespace std;

// Maximum number of ice cream bars that can be purchased.
int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int count = 0;

    for (int cost : costs) {
        if (coins < cost)
            break;

        coins -= cost;
        count++;
    }

    return count;
}
