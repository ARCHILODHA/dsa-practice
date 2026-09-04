#include <iostream>
#include <vector>
using namespace std;

int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    // Base case
    if (low >= high)
        return;

    // Partition array
    int pivotIndex = partitionArray(arr, low, high);

    // Recursively sort left part
    quickSort(arr, low, pivotIndex - 1);

    // Recursively sort right part
    quickSort(arr, pivotIndex + 1, high);
}

int main() {
    vector<int> arr = {
        10, 7, 8, 9, 1, 5
    };

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";

    for (int value : arr)
        cout << value << " ";

    cout << endl;

    return 0;
}
