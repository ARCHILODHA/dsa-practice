#include <string>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {

        int bal=0;
        int ans=0;

        for(char c:s){

            if(c=='L')
                bal++;
            else
                bal--;

            if(bal==0)
                ans++;
        }

        return ans;
    }
};
