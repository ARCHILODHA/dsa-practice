#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 1) return true;
    return arr[n - 2] <= arr[n - 1] && isSorted(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << isSorted(arr, 5);
}
