#include <bits/stdc++.h>
using namespace std;

void solve(int index, vector<int>& arr, int target,
           vector<int>& current, vector<vector<int>>& ans) {

    if (target == 0) {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        if (i > index && arr[i] == arr[i - 1])
            continue;

        if (arr[i] > target)
            break;

        current.push_back(arr[i]);

        solve(i + 1, arr, target - arr[i], current, ans);

        current.pop_back();
    }
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    sort(arr.begin(), arr.end());

    vector<int> current;
    vector<vector<int>> ans;

    solve(0, arr, target, current, ans);

    for (auto& combination : ans) {
        for (int x : combination)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
