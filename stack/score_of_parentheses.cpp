#include <iostream>
#include <stack>
using namespace std;

int scoreOfParentheses(string s){
    stack<int> st;
    st.push(0);

    for(char c:s){
        if(c=='(') st.push(0);
        else{
            int v=st.top(); st.pop();
            int score=max(2*v,1);
            st.top()+=score;
        }
    }
    return st.top();
}

int main(){
    cout<<scoreOfParentheses("(()(()))");
}
