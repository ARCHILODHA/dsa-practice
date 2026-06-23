#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    if (s.length() <= 1) return s;

    string smallAns = removeDuplicates(s.substr(1));

    if (s[0] == smallAns[0])
        return smallAns;

    return s[0] + smallAns;
}

int main() {
    cout << removeDuplicates("aaabbbccdd");
}
