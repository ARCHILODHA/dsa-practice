#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> lastIndex(10, -1);

        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - '0'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            for (int digit = 9; digit > s[i] - '0'; digit--) {
                if (lastIndex[digit] > i) {
                    swap(s[i], s[lastIndex[digit]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};
