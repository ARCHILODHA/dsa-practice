#include <bits/stdc++.h>
using namespace std;

int kthGrammar(int n, long long k) {
    if (n == 1) return 0;

    long long mid = 1LL << (n - 2);

    if (k <= mid) {
        return kthGrammar(n - 1, k);
    }

    return 1 - kthGrammar(n - 1, k - mid);
}

int main() {
    int n;
    long long k;

    cin >> n >> k;

    cout << kthGrammar(n, k);

    return 0;
}
