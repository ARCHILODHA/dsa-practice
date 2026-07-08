#include <iostream>
#include <vector>
using namespace std;

vector<int> rearrange(vector<int>& nums) {
    vector<int> ans(nums.size());

    int pos=0, neg=1;

    for(int x:nums){
        if(x>=0){
            ans[pos]=x;
            pos+=2;
        }else{
            ans[neg]=x;
            neg+=2;
        }
    }

    return ans;
}

int main() {
    vector<int> nums={3,1,-2,-5,2,-4};

    vector<int> ans=rearrange(nums);

    for(int x:ans)
        cout<<x<<" ";
}
