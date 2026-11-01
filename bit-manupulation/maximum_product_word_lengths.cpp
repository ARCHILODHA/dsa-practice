#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<string>& words) {
    int n = words.size();

    vector<int> masks(n, 0);

    for (int i = 0; i < n; i++) {

        for (char ch : words[i]) {
            masks[i] |= (1 << (ch - 'a'));
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            if ((masks[i] & masks[j]) == 0) {
                int product = words[i].size() * words[j].size();

                ans = max(ans, product);
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << maxProduct(words);

    return 0;
}
