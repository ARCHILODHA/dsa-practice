#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r) {
    if (l >= r)
        return true;

    if (s[l] != s[r])
        return false;

    return isPalindrome(s, l + 1, r - 1);
}
