#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& arr, int students, int limit) {
    int count = 1, pages = 0;

    for (int x : arr) {
        if (pages + x > limit) {
            count++;
            pages = x;
        } else {
            pages += x;
        }
    }

    return count <= students;
}

int allocateBooks(vector<int>& arr, int students) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (possible(arr, students, mid))
            high = mid - 1;
        else
            low = mid + 1;
    }

    return low;
}
