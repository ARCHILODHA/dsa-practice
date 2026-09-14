#include <bits/stdc++.h>
using namespace std;

// Maximum profit when you can buy and sell multiple times.
// You cannot hold multiple stocks at the same time.
//
// Time: O(n)
// Space: O(1)

int maxProfit(vector<int>& prices) {
    int profit = 0;

    for (int i = 1; i < prices.size(); i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }

    return profit;
}

int main() {
    vector<int> prices = {
        7, 1, 5, 3, 6, 4
    };

    cout << "Maximum profit: "
         << maxProfit(prices) << endl;

    return 0;
}
