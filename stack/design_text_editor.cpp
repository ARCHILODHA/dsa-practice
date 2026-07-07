#include <iostream>
#include <stack>
using namespace std;

class TextEditor{
    stack<char> left,right;

public:
    void addText(string s){
        for(char c:s) left.push(c);
    }

    void deleteText(int k){
        while(k-- && !left.empty())
            left.pop();
    }

    void cursorLeft(int k){
        while(k-- && !left.empty()){
            right.push(left.top());
            left.pop();
        }
    }

    void cursorRight(int k){
        while(k-- && !right.empty()){
            left.push(right.top());
            right.pop();
        }
    }

    void display(){
        stack<char> temp=left;
        string s="";
        while(!temp.empty()){
            s=temp.top()+s;
            temp.pop();
        }
        cout<<s<<endl;
    }
};

int main(){
    TextEditor t;
    t.addText("hello");
    t.deleteText(2);
    t.addText("p");
    t.display();
}
