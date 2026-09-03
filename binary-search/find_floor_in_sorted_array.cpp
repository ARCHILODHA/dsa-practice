#include <iostream>
#include <vector>
using namespace std;

// Largest element <= target
int findFloor(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target) {
            answer = arr[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16};

    int target = 10;

    cout << "Floor: "
         << findFloor(arr, target) << endl;

    return 0;
}
