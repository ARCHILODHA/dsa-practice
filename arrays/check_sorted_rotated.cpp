#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int>& nums){
    int count=0;

    for(int i=0;i<nums.size();i++){
        if(nums[i]>nums[(i+1)%nums.size()])
            count++;
    }

    return count<=1;
}

int main(){
    vector<int> nums={3,4,5,1,2};

    cout<<check(nums);
}
