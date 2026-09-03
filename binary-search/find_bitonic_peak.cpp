#include <iostream>
#include <vector>
using namespace std;

// Bitonic array first increases and then decreases.
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

int main() {
    vector<int> arr = {1, 3, 8, 12, 4, 2};

    int peakIndex = findPeak(arr);

    cout << "Peak index: " << peakIndex << endl;
    cout << "Peak value: " << arr[peakIndex] << endl;

    return 0;
}
