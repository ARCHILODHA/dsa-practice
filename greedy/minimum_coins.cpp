int minCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend());
    int count = 0;

    for(int coin : coins) {
        count += amount / coin;
        amount %= coin;
    }
    return amount == 0 ? count : -1;
}
