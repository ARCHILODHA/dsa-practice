#include <iostream>
#include <stack>
using namespace std;

int precedence(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    if(c=='^') return 3;
    return -1;
}

int main(){
    string exp;
    cin >> exp;

    stack<char> st;
    string result="";

    for(char c:exp){

        if(isalnum(c))
            result+=c;

        else if(c=='(')
            st.push(c);

        else if(c==')'){
            while(st.top()!='('){
                result+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && precedence(st.top())>=precedence(c)){
                result+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        result+=st.top();
        st.pop();
    }

    cout<<result;
}
