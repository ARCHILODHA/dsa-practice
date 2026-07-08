#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int secondLargest(vector<int>& arr){
    int first=INT_MIN, second=INT_MIN;

    for(int x:arr){
        if(x>first){
            second=first;
            first=x;
        }else if(x>second && x!=first){
            second=x;
        }
    }

    return second;
}

int main(){
    vector<int> arr={12,35,1,10,34,1};

    cout<<secondLargest(arr);
}
