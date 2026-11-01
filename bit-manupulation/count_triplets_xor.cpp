#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;

    vector<int> prefix(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {

            if (prefix[i] == prefix[k + 1]) {
                ans += k - i;
            }
        }
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

    cout << countTriplets(arr);

    return 0;
}
