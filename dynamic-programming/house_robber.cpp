class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = 0, curr = 0;

        for(int num : nums) {
            int temp = max(curr, prev + num);
            prev = curr;
            curr = temp;
        }

        return curr;
    }
};
