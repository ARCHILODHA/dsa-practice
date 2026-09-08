#include <bits/stdc++.h>
using namespace std;

// Best Time to Buy and Sell Stock
// At most one transaction.
// Time: O(n)
// Space: O(1)

int main() {
    int n;
    cin >> n;

    vector<int> prices(n);

    for (int &x : prices)
        cin >> x;

    int minimumPrice = INT_MAX;
    int maximumProfit = 0;

    for (int price : prices) {
        minimumPrice = min(minimumPrice, price);

        maximumProfit = max(
            maximumProfit,
            price - minimumPrice
        );
    }

    cout << "Maximum profit: " << maximumProfit << endl;

    return 0;
}
