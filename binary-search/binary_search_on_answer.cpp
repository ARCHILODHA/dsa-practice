bool possible(vector<int>& arr, int mid) {
    // custom logic
    return true;
}

int solve(vector<int>& arr) {
    int low = 0, high = 1e9, ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(possible(arr, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
