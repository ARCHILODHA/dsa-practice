#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinimum(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    return arr[low];
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

    cout << "Minimum element: "
         << findMinimum(arr) << endl;

    return 0;
}
