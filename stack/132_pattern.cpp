#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Check whether there exist i < j < k such that:
// arr[i] < arr[k] < arr[j]
bool find132pattern(vector<int>& arr) {
    int n = arr.size();

    if (n < 3)
        return false;

    stack<int> st;

    // Represents the "2" in the 132 pattern.
    int middle = -2147483648;

    // Traverse from right to left.
    for (int i = n - 1; i >= 0; i--) {

        // Current element can be the "1".
        if (arr[i] < middle)
            return true;

        // Find a suitable "2".
        while (!st.empty() && arr[i] > st.top()) {
            middle = st.top();
            st.pop();
        }

        st.push(arr[i]);
    }

    return false;
}

int main() {
    vector<int> arr = {
        3, 1, 4, 2
    };

    if (find132pattern(arr))
        cout << "132 pattern exists" << endl;
    else
        cout << "132 pattern does not exist" << endl;

    return 0;
}
