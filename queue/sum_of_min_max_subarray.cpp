#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
    vector<int> arr = {2,5,-1,7,-3,-1,-2};
    int k = 4;

    deque<int> maxi, mini;

    for(int i=0;i<k;i++) {
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    cout << arr[maxi.front()] + arr[mini.front()];
}
