#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;

    int i = low;
    int j = mid + 1;

    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= high) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[low + k] = temp[k];
    }
}

void mergeSort(vector<int>& arr, int low, int high) {
    // Base case
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both halves
    mergeArrays(arr, low, mid, high);
}

int main() {
    vector<int> arr = {
        38, 27, 43, 3, 9, 82, 10
    };

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";

    for (int value : arr)
        cout << value << " ";

    cout << endl;

    return 0;
}
