#include <iostream>
#include <vector>
using namespace std;

// Number of rotations = index of minimum element.
int rotationCount(vector<int>& arr) {
    int low = 0;
    int high = arr.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    vector<int> arr = {15, 18, 2, 3, 6, 12};

    cout << "Number of rotations: "
         << rotationCount(arr) << endl;

    return 0;
}
