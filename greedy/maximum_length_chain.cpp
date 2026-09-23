#include <bits/stdc++.h>
using namespace std;

struct PairValue {
    int first;
    int second;
};

// Maximum length chain of pairs.
int findLongestChain(vector<PairValue>& pairs) {
    sort(pairs.begin(), pairs.end(),
         [](const PairValue& a, const PairValue& b) {
             return a.second < b.second;
         });

    int count = 0;
    int lastEnd = INT_MIN;

    for (auto& p : pairs) {
        if (p.first > lastEnd) {
            count++;
            lastEnd = p.second;
        }
    }

    return count;
}
