#include <iostream>
#include <vector>
using namespace std;

int calPoints(vector<string>& ops){
    vector<int> st;

    for(string s:ops){
        if(s=="+")
            st.push_back(st.back()+st[st.size()-2]);
        else if(s=="D")
            st.push_back(2*st.back());
        else if(s=="C")
            st.pop_back();
        else
            st.push_back(stoi(s));
    }

    int sum=0;
    for(int x:st) sum+=x;
    return sum;
}

int main(){
    vector<string> ops={"5","2","C","D","+"};
    cout<<calPoints(ops);
}
