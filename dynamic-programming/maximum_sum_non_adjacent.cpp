#include <bits/stdc++.h>
using namespace std;

// Maximum Sum of Non-Adjacent Elements
// Time: O(n)
// Space: O(1)

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int &x : arr)
        cin >> x;

    int prev2 = 0;
    int prev1 = 0;

    for (int x : arr) {
        int take = x + prev2;
        int skip = prev1;

        int current = max(take, skip);

        prev2 = prev1;
        prev1 = current;
    }

    cout << "Maximum sum: " << prev1 << endl;

    return 0;
}
