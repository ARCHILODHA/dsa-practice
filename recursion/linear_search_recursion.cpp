#include <iostream>
using namespace std;

bool linearSearch(int arr[], int n, int key) {
    if (n == 0) return false;
    if (arr[0] == key) return true;
    return linearSearch(arr + 1, n - 1, key);
}

int main() {
    int arr[] = {10, 20, 30, 40};
    cout << linearSearch(arr, 4, 30);
}
