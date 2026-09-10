#include <bits/stdc++.h>
using namespace std;

// Merge two sorted arrays without using another sorting algorithm.

vector<int> mergeSortedArrays(vector<int>& a, vector<int>& b) {
    vector<int> result;

    int i = 0;
    int j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            result.push_back(a[i++]);
        } else {
            result.push_back(b[j++]);
        }
    }

    while (i < a.size()) {
        result.push_back(a[i++]);
    }

    while (j < b.size()) {
        result.push_back(b[j++]);
    }

    return result;
}

int main() {
    vector<int> a = {1, 3, 5, 7};
    vector<int> b = {2, 4, 6, 8};

    vector<int> result = mergeSortedArrays(a, b);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
