// Frog Jump (Minimum Energy)
class Solution {
public:
    int frogJump(int n, vector<int>& h) {
        vector<int> dp(n, 0);

        for(int i = 1; i < n; i++) {
            int one = dp[i-1] + abs(h[i] - h[i-1]);
            int two = INT_MAX;
            if(i > 1)
                two = dp[i-2] + abs(h[i] - h[i-2]);

            dp[i] = min(one, two);
        }

        return dp[n-1];
    }
};
