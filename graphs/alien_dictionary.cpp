#include <bits/stdc++.h>
using namespace std;

string findOrder(string dict[], int N, int K) {
    vector<int> adj[K];

    for(int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int len = min(s1.size(), s2.size());

        for(int j = 0; j < len; j++) {
            if(s1[j] != s2[j]) {
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                break;
            }
        }
    }

    return "";
}
