#include <bits/stdc++.h>
using namespace std;

int minFlips(int a, int b, int c) {
    int ans = 0;

    while (a > 0 || b > 0 || c > 0) {
        int bitA = a & 1;
        int bitB = b & 1;
        int bitC = c & 1;

        if (bitC == 1) {
            if (bitA == 0 && bitB == 0) {
                ans++;
            }
        }
        else {
            ans += bitA + bitB;
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    return ans;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << minFlips(a, b, c);

    return 0;
}
