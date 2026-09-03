#include <iostream>
#include <vector>
using namespace std;

// Every element is at most one position away from its
// correct position.
int searchNearlySorted(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (mid - 1 >= low && arr[mid - 1] == target)
            return mid - 1;

        if (mid + 1 <= high && arr[mid + 1] == target)
            return mid + 1;

        if (arr[mid] > target)
            high = mid - 2;
        else
            low = mid + 2;
    }

    return -1;
}

int main() {
    vector<int> arr = {10, 3, 40, 20, 50, 80, 70};

    int target = 40;

    cout << "Target index: "
         << searchNearlySorted(arr, target) << endl;

    return 0;
}
