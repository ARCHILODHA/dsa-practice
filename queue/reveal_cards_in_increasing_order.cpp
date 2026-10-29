#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());

        int n = deck.size();
        deque<int> indices;

        for (int i = 0; i < n; i++) {
            indices.push_back(i);
        }

        vector<int> result(n);

        for (int card : deck) {
            int index = indices.front();
            indices.pop_front();

            result[index] = card;

            if (!indices.empty()) {
                indices.push_back(indices.front());
                indices.pop_front();
            }
        }

        return result;
    }
};
