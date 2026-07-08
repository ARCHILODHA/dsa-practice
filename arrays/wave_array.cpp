#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void wave(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    for(int i=0;i+1<arr.size();i+=2)
        swap(arr[i], arr[i+1]);
}

int main() {
    vector<int> arr={3,6,5,10,7,20};

    wave(arr);

    for(int x:arr)
        cout<<x<<" ";
}
