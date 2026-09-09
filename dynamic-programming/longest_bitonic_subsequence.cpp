#include <bits/stdc++.h>
using namespace std;

// Longest Bitonic Subsequence
// Increasing followed by decreasing.
// Time: O(n^2)
// Space: O(n)

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &x : arr)
        cin >> x;

    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    // Longest Increasing Subsequence ending at i
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                lis[i] = max(lis[i], lis[j] + 1);
        }
    }

    // Longest Decreasing Subsequence starting at i
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i])
                lds[i] = max(lds[i], lds[j] + 1);
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        answer = max(
            answer,
            lis[i] + lds[i] - 1
        );
    }

    cout << "Longest bitonic subsequence: "
         << answer << endl;

    return 0;
}
