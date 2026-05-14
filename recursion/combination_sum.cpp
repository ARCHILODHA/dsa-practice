#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int target, int idx, vector<int>& temp) {
    if (target == 0) {
        for (int x : temp)
            cout << x << " ";
        cout << endl;
        return;
    }

    if (idx == arr.size() || target < 0)
        return;

    temp.push_back(arr[idx]);
    solve(arr, target - arr[idx], idx, temp);

    temp.pop_back();
    solve(arr, target, idx + 1, temp);
}
