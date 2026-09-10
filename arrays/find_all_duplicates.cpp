#include <bits/stdc++.h>
using namespace std;

// Find all elements that appear twice.
// Values are assumed to be in the range [1, n].

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;

    for (int x : nums) {
        int index = abs(x) - 1;

        if (nums[index] < 0) {
            result.push_back(abs(x));
        } else {
            nums[index] *= -1;
        }
    }

    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    vector<int> duplicates = findDuplicates(nums);

    cout << "Duplicates: ";

    for (int x : duplicates) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
