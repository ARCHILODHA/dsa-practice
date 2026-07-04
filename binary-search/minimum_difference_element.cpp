#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minimumDifference(vector<int>& arr,int target){

    int l=0,r=arr.size()-1;

    while(l<=r){

        int mid=l+(r-l)/2;

        if(arr[mid]==target)
            return arr[mid];

        if(arr[mid]<target)
            l=mid+1;
        else
            r=mid-1;
    }

    if(l>=arr.size()) return arr[r];
    if(r<0) return arr[l];

    if(abs(arr[l]-target)<abs(arr[r]-target))
        return arr[l];

    return arr[r];
}
