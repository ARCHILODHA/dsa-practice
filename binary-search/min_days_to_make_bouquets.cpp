bool canMake(vector<int>& bloomDay, int m, int k, int day) {
    int count = 0, bouquets = 0;

    for (int d : bloomDay) {
        if (d <= day) {
            count++;
            if (count == k) {
                bouquets++;
                count = 0;
            }
        } else count = 0;
    }
    return bouquets >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    if ((long long)m * k > bloomDay.size()) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low < high) {
        int mid = (low + high) / 2;
        if (canMake(bloomDay, m, k, mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}
