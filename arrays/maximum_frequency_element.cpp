#include <bits/stdc++.h>
using namespace std;

// Find the element with the highest frequency.
// If multiple elements have the same frequency,
// the first encountered element is returned.

int mostFrequentElement(vector<int>& nums) {
    unordered_map<int, int> frequency;

    int answer = nums[0];
    int maxFrequency = 0;

    for (int x : nums) {
        frequency[x]++;

        if (frequency[x] > maxFrequency) {
            maxFrequency = frequency[x];
            answer = x;
        }
    }

    return answer;
}

int main() {
    vector<int> nums = {
        1, 3, 2, 1, 4, 1, 3, 2
    };

    cout << "Most frequent element: "
         << mostFrequentElement(nums) << endl;

    return 0;
}
