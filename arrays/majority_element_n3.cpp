#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0;
    int ele1 = 0, ele2 = 0;

    for(int x : nums) {
        if(x == ele1) cnt1++;
        else if(x == ele2) cnt2++;
        else if(cnt1 == 0) {
            ele1 = x;
            cnt1 = 1;
        }
        else if(cnt2 == 0) {
            ele2 = x;
            cnt2 = 1;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;

    for(int x : nums) {
        if(x == ele1) cnt1++;
        else if(x == ele2) cnt2++;
    }

    vector<int> ans;
    if(cnt1 > nums.size()/3) ans.push_back(ele1);
    if(cnt2 > nums.size()/3) ans.push_back(ele2);

    return ans;
}

int main() {
    vector<int> nums = {3,2,3};

    vector<int> ans = majorityElement(nums);

    for(int x : ans)
        cout << x << " ";
}
