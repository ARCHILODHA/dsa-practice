int findMaximumXOR(vector<int>& nums) {
    int maxXor = 0, mask = 0;
    unordered_set<int> s;

    for(int i=31;i>=0;i--){
        mask |= (1<<i);
        s.clear();

        for(int num:nums)
            s.insert(num & mask);

        int temp = maxXor | (1<<i);

        for(int prefix:s){
            if(s.count(prefix ^ temp)){
                maxXor = temp;
                break;
            }
        }
    }
    return maxXor;
}
