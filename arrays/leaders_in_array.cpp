#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    vector<int> ans;
    int maxi = INT_MIN;

    for (int i = arr.size() - 1; i >= 0; i--) {
        if (arr[i] >= maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    vector<int> arr = {16,17,4,3,5,2};

    vector<int> res = leaders(arr);

    for(int x : res)
        cout << x << " ";
}
