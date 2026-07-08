#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> a={1,2,2,3,4};
    vector<int> b={2,2,4,6};

    set<int> ans;

    for(int x:a){
        for(int y:b){
            if(x==y)
                ans.insert(x);
        }
    }

    for(int x:ans)
        cout<<x<<" ";
}
