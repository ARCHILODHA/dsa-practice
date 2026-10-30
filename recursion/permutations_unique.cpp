#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, vector<bool>& used,
           vector<int>& current, vector<vector<int>>& ans) {

    if (current.size() == arr.size()) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {

        if (used[i]) continue;

        if (i > 0 && arr[i] == arr[i - 1] && !used[i - 1])
            continue;

        used[i] = true;
        current.push_back(arr[i]);

        solve(arr, used, current, ans);

        current.pop_back();
        used[i] = false;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    vector<bool> used(n, false);
    vector<int> current;
    vector<vector<int>> ans;

    solve(arr, used, current, ans);

    for (auto& permutation : ans) {
        for (int x : permutation)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}
