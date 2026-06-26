#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();

        for (int i = 0; i < m && n > 0; i++) {
            if (flowerbed[i] == 0 &&
                (i == 0 || flowerbed[i - 1] == 0) &&
                (i == m - 1 || flowerbed[i + 1] == 0)) {

                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};
