#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int idx, int sum) {
    if (idx == arr.size()) {
        cout << sum << endl;
        return;
    }

    solve(arr, idx + 1, sum + arr[idx]);
    solve(arr, idx + 1, sum);
}
