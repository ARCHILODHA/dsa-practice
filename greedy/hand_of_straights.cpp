#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }

        map<int, int> freq;

        for (int card : hand) {
            freq[card]++;
        }

        while (!freq.empty()) {
            int first = freq.begin()->first;

            for (int card = first;
                 card < first + groupSize; card++) {

                if (freq.find(card) == freq.end()) {
                    return false;
                }

                freq[card]--;

                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};
