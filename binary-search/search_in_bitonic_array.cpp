#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int ascendingSearch(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int descendingSearch(vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int searchBitonic(vector<int>& arr, int target) {
    int peak = findPeak(arr);

    int result = ascendingSearch(arr, 0, peak, target);

    if (result != -1)
        return result;

    return descendingSearch(
        arr, peak + 1, arr.size() - 1, target
    );
}

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};

    int target = 4;

    cout << "Target index: "
         << searchBitonic(arr, target) << endl;

    return 0;
}
