#include <bits/stdc++.h>
using namespace std;

void permute(vector<int>& nums, int i) {
    if(i == nums.size()){
        for(int x: nums) cout << x << " ";
        cout << endl;
        return;
    }

    for(int j=i;j<nums.size();j++){
        swap(nums[i], nums[j]);
        permute(nums, i+1);
        swap(nums[i], nums[j]);
    }
}
