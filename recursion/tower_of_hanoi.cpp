#include <bits/stdc++.h>
using namespace std;

void toh(int n, char src, char aux, char dest) {
    if (n == 0)
        return;

    toh(n - 1, src, dest, aux);

    cout << src << " -> " << dest << endl;

    toh(n - 1, aux, src, dest);
}
