#include <iostream>
#include <stack>
using namespace std;

string build(string s){
    stack<char> st;

    for(char c:s){
        if(c=='#'){
            if(!st.empty()) st.pop();
        }else
            st.push(c);
    }

    string ans="";
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}

int main(){
    cout<<(build("ab#c")==build("ad#c"));
}
