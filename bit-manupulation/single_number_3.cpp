vector<int> singleNumber(vector<int>& nums) {
    int x = 0;
    for(int n : nums) x ^= n;

    int diff = x & (-x);
    int a = 0, b = 0;

    for(int n : nums) {
        if(n & diff) a ^= n;
        else b ^= n;
    }
    return {a, b};
}
