#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(),boxTypes.end(),[](auto &a,auto &b){
            return a[1]>b[1];
        });

        int ans=0;

        for(auto x:boxTypes){

            int take=min(truckSize,x[0]);

            ans+=take*x[1];
            truckSize-=take;

            if(truckSize==0)
                break;
        }

        return ans;
    }
};
