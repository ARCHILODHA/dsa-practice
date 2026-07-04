#include <iostream>
#include <vector>
using namespace std;

int ceilElement(vector<int>& arr,int x){

    int ans=-1;

    int l=0,r=arr.size()-1;

    while(l<=r){

        int mid=l+(r-l)/2;

        if(arr[mid]>=x){
            ans=arr[mid];
            r=mid-1;
        }
        else
            l=mid+1;
    }

    return ans;
}

int main(){

    vector<int> arr={1,3,5,7,9};

    cout<<ceilElement(arr,6);

}
