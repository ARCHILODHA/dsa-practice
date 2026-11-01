#include <bits/stdc++.h>
using namespace std;

vector<int> findArray(vector<int>& pref) {
    int n = pref.size();

    vector<int> ans(n);

    if (n == 0) return ans;

    ans[0] = pref[0];

    for (int i = 1; i < n; i++) {
        ans[i] = pref[i] ^ pref[i - 1];
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> pref(n);

    for (int i = 0; i < n; i++) {
        cin >> pref[i];
    }

    vector<int> ans = findArray(pref);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
