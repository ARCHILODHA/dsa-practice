#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& boards, int painters, int limit) {
    int count = 1, total = 0;

    for (int x : boards) {
        if (total + x > limit) {
            count++;
            total = x;
        } else {
            total += x;
        }
    }

    return count <= painters;
}

int paintersPartition(vector<int>& boards, int painters) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    while (low <= high) {
        int mid = (low + high) / 2;

        if (possible(boards, painters, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}
