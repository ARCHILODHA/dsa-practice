#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int>& nums){
    int cnt=0, ans=0;

    for(int x:nums){
        if(x==1){
            cnt++;
            ans=max(ans,cnt);
        }else{
            cnt=0;
        }
    }

    return ans;
}

int main(){
    vector<int> nums={1,1,0,1,1,1};

    cout<<findMax(nums);
}
