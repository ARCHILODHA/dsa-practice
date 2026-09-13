#include <bits/stdc++.h>
using namespace std;

// Find the maximum number of chunks into which an array
// can be divided such that sorting each chunk individually
// results in the entire array being sorted.
//
// Assumes the array contains a permutation of [0, n-1].

int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0;
    int maxValue = 0;

    for (int i = 0; i < arr.size(); i++) {
        maxValue = max(maxValue, arr[i]);

        if (maxValue == i) {
            chunks++;
        }
    }

    return chunks;
}

int main() {
    vector<int> arr = {1, 0, 2, 3, 4};

    cout << "Maximum chunks: "
         << maxChunksToSorted(arr) << endl;

    return 0;
}
