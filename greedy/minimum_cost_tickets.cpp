#include <bits/stdc++.h>
using namespace std;

// Minimum cost to cover all travel days.
int mincostTickets(vector<int>& days, vector<int>& costs) {
    int lastDay = days.back();

    vector<int> dp(lastDay + 1, 0);
    vector<bool> travel(lastDay + 1, false);

    for (int day : days)
        travel[day] = true;

    for (int day = 1; day <= lastDay; day++) {
        if (!travel[day]) {
            dp[day] = dp[day - 1];
        } else {
            int oneDay = dp[max(0, day - 1)] + costs[0];

            int sevenDay =
                dp[max(0, day - 7)] + costs[1];

            int thirtyDay =
                dp[max(0, day - 30)] + costs[2];

            dp[day] = min({
                oneDay,
                sevenDay,
                thirtyDay
            });
        }
    }

    return dp[lastDay];
}
