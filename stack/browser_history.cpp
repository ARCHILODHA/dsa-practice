#include <bits/stdc++.h>
using namespace std;

class BrowserHistory {
    stack<string> backStack;
    stack<string> forwardStack;
    string current;

public:
    BrowserHistory(string homepage) {
        current = homepage;
    }

    void visit(string url) {
        backStack.push(current);
        current = url;

        while(!forwardStack.empty())
            forwardStack.pop();
    }

    string back() {
        if(backStack.empty()) return current;

        forwardStack.push(current);
        current = backStack.top();
        backStack.pop();

        return current;
    }

    string forward() {
        if(forwardStack.empty()) return current;

        backStack.push(current);
        current = forwardStack.top();
        forwardStack.pop();

        return current;
    }
};
