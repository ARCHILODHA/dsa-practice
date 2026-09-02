#include <iostream>
#include <queue>
#include <string>
using namespace std;

string getKthPalindrome(int k) {
    queue<string> q;

    q.push("1");
    q.push("2");

    string result;

    while (k > 0) {
        string current = q.front();
        q.pop();

        result = current;

        q.push(current + "0");
        q.push(current + "1");

        k--;
    }

    string reversePart = result;

    reverse(reversePart.begin(), reversePart.end());

    return result + reversePart;
}

int main() {
    int k = 5;

    cout << "Palindrome: "
         << getKthPalindrome(k) << endl;

    return 0;
}
