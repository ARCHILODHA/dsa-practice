#include <iostream>
using namespace std;

string removeOuterParentheses(string s){
    string ans="";
    int cnt=0;

    for(char c:s){
        if(c=='('){
            if(cnt>0) ans+=c;
            cnt++;
        }else{
            cnt--;
            if(cnt>0) ans+=c;
        }
    }
    return ans;
}

int main(){
    cout<<removeOuterParentheses("(()())(())");
}
