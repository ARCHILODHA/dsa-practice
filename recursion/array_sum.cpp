#include <iostream>
using namespace std;

int arraySum(int arr[], int n) {
    if (n == 0) return 0;
    return arr[n - 1] + arraySum(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << arraySum(arr, 5);
}
