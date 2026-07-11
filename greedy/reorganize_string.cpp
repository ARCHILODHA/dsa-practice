#include <string>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {

        vector<int> freq(26);

        for(char c:s)
            freq[c-'a']++;

        priority_queue<pair<int,char>> pq;

        for(int i=0;i<26;i++)
            if(freq[i])
                pq.push({freq[i],char(i+'a')});

        string ans;

        while(pq.size()>1){

            auto a=pq.top(); pq.pop();
            auto b=pq.top(); pq.pop();

            ans+=a.second;
            ans+=b.second;

            if(--a.first)
                pq.push(a);

            if(--b.first)
                pq.push(b);
        }

        if(!pq.empty()){

            if(pq.top().first>1)
                return "";

            ans+=pq.top().second;
        }

        return ans;
    }
};
