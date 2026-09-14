#include <bits/stdc++.h>
using namespace std;

// Find common elements present in three sorted arrays.
//
// Time: O(n1 + n2 + n3)
// Space: O(1), excluding the answer.

vector<int> commonElements(vector<int>& a,
                            vector<int>& b,
                            vector<int>& c) {
    int i = 0;
    int j = 0;
    int k = 0;

    vector<int> result;

    while (i < a.size() &&
           j < b.size() &&
           k < c.size()) {

        if (a[i] == b[j] && b[j] == c[k]) {
            if (result.empty() || result.back() != a[i]) {
                result.push_back(a[i]);
            }

            i++;
            j++;
            k++;
        }
        else {
            int minimumValue = min({a[i], b[j], c[k]});

            if (a[i] == minimumValue) i++;
            if (b[j] == minimumValue) j++;
            if (c[k] == minimumValue) k++;
        }
    }

    return result;
}

int main() {
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> result = commonElements(a, b, c);

    cout << "Common elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
