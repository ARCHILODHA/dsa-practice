#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());

        int l = 0, r = tokens.size() - 1;
        int score = 0, ans = 0;

        while (l <= r) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                score++;
                ans = max(ans, score);
            } else if (score > 0) {
                power += tokens[r--];
                score--;
            } else
                break;
        }

        return ans;
    }
};
