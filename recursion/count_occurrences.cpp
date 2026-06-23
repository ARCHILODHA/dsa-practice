#include <iostream>
using namespace std;

int countOccurrences(int arr[], int n, int key) {
    if (n == 0) return 0;
    return (arr[n - 1] == key) +
           countOccurrences(arr, n - 1, key);
}

int main() {
    int arr[] = {1, 2, 1, 3, 1};
    cout << countOccurrences(arr, 5, 1);
}
