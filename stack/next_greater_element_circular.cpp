#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Find the next greater element considering the array as circular.
vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();

    vector<int> result(n, -1);
    stack<int> st;

    // Traverse the array twice to simulate circular behavior.
    for (int i = 2 * n - 1; i >= 0; i--) {

        int index = i % n;

        // Remove elements that cannot be the answer.
        while (!st.empty() && st.top() <= arr[index])
            st.pop();

        // Only the first traversal stores answers.
        if (i < n) {
            if (!st.empty())
                result[index] = st.top();
        }

        st.push(arr[index]);
    }

    return result;
}

int main() {
    vector<int> arr = {
        1, 2, 1
    };

    vector<int> result = nextGreaterElements(arr);

    cout << "Next Greater Elements: ";

    for (int value : result)
        cout << value << " ";

    cout << endl;

    return 0;
}
