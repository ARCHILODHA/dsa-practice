#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    vector<int> arr = {4,5,2,10};
    int n = arr.size();

    vector<int> res(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i])
            st.pop();

        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();

        st.push(arr[i]);
    }

    for(int x:res)
        cout<<x<<" ";
}
