#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> a={1,2,3,4};
    vector<int> b={3,4,5,6};

    set<int> s;

    for(int x:a) s.insert(x);
    for(int x:b) s.insert(x);

    for(int x:s)
        cout<<x<<" ";
}
