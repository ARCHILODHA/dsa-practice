#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock II
// Unlimited transactions.
// Time: O(n)
// Space: O(1)

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int &x : prices)
        cin >> x;

    int cash = 0;
    int hold = -prices[0];

    for (int i = 1; i < n; i++) {
        int newCash = max(cash, hold + prices[i]);
        int newHold = max(hold, cash - prices[i]);

        cash = newCash;
        hold = newHold;
    }

    cout << "Maximum profit: " << cash << endl;

    return 0;
}
