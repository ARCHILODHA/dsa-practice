#include <iostream>
#include <vector>
using namespace std;

// Smallest element >= target
int findCeil(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            answer = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> arr = {2, 5, 8, 12, 16};

    int target = 10;

    cout << "Ceil: "
         << findCeil(arr, target) << endl;

    return 0;
}
