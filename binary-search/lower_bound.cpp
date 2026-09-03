#include <iostream>
#include <vector>
using namespace std;

// Find the first index where arr[index] >= target
int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    int answer = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    vector<int> arr = {1, 2, 4, 4, 6, 8};
    int target = 4;

    cout << "Lower bound index: "
         << lowerBound(arr, target) << endl;

    return 0;
}
