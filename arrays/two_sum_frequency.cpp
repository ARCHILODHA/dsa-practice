
#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int target) {
    unordered_map<int, int> freq;
    int count = 0;

    for (int num : arr) {
        int complement = target - num;

        if (freq.count(complement)) {
            count += freq[complement];
        }

        freq[num]++;
    }

    return count;
}

int main() {
    int n, target;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> target;

    cout << countPairs(arr, target) << endl;

    return 0;
}
