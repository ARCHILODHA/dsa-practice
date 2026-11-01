#include <bits/stdc++.h>
using namespace std;

vector<int> xorQueries(
    vector<int>& arr,
    vector<vector<int>>& queries
) {
    int n = arr.size();

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    vector<int> ans;

    for (auto& query : queries) {
        int left = query[0];
        int right = query[1];

        ans.push_back(prefix[right + 1] ^ prefix[left]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    vector<vector<int>> queries(q, vector<int>(2));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }

    vector<int> ans = xorQueries(arr, queries);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
