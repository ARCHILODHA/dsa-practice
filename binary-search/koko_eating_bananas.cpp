bool canEat(vector<int>& piles, int h, int speed) {
    long long time = 0;
    for(int p : piles)
        time += (p + speed - 1) / speed;
    return time <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());

    while(l < r) {
        int mid = (l + r) / 2;
        if(canEat(piles, h, mid)) r = mid;
        else l = mid + 1;
    }
    return l;
}
