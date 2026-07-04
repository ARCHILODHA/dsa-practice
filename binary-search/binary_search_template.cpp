#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target) {

    int low = 0;
    int high = arr.size() - 1;

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

int main() {

    vector<int> arr = {2,4,6,8,10};

    cout << binarySearch(arr,8);

    return 0;
}
