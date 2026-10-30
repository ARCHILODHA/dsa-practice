#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k, string& result, vector<int>& nums,
           vector<int>& fact) {

    if (n == 0) return;

    int blockSize = fact[n - 1];

    int index = k / blockSize;

    result += to_string(nums[index]);

    nums.erase(nums.begin() + index);

    k %= blockSize;

    solve(n - 1, k, result, nums, fact);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> fact(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    if (k < 1 || k > fact[n]) {
        cout << "Invalid K";
        return 0;
    }

    vector<int> nums;

    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    string result;

    solve(n, k - 1, result, nums, fact);

    cout << result;

    return 0;
}
