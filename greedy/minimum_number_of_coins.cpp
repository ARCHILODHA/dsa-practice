#include <bits/stdc++.h>
using namespace std;

// Find minimum number of Indian currency coins/notes.
int minimumCoins(int amount) {
    vector<int> coins = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int count = 0;

    for (int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }

    return count;
}
