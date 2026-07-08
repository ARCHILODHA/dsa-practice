#include <iostream>
#include <vector>
using namespace std;

int equilibriumIndex(vector<int>& arr) {
    int total = 0;
    for(int x : arr) total += x;

    int left = 0;

    for(int i = 0; i < arr.size(); i++) {
        total -= arr[i];

        if(left == total)
            return i;

        left += arr[i];
    }

    return -1;
}

int main() {
    vector<int> arr = {1,3,5,2,2};

    cout << equilibriumIndex(arr);
}
