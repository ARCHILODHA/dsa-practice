#include <iostream>
#include <vector>
using namespace std;

int floorElement(vector<int>& arr,int x){

    int ans=-1;
    int l=0,r=arr.size()-1;

    while(l<=r){

        int mid=l+(r-l)/2;

        if(arr[mid]<=x){
            ans=arr[mid];
            l=mid+1;
        }
        else
            r=mid-1;
    }

    return ans;
}

int main(){

    vector<int> arr={1,2,4,6,10};

    cout<<floorElement(arr,5);

}
