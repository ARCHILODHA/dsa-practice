#include <iostream>
#include <stack>
using namespace std;

string removeStars(string s){
    stack<char> st;

    for(char c:s){
        if(c=='*'){
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
    cout<<removeStars("leet**cod*e");
}
