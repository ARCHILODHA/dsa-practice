#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Check whether pushed and popped sequences can represent
// a valid sequence of stack operations.
bool validateStackSequences(
    vector<int>& pushed,
    vector<int>& popped
) {
    stack<int> st;

    int j = 0;

    for (int value : pushed) {

        // Push the current value.
        st.push(value);

        // Pop whenever the top matches the required
        // element in the popped sequence.
        while (!st.empty() &&
               j < popped.size() &&
               st.top() == popped[j]) {

            st.pop();
            j++;
        }
    }

    return st.empty();
}

int main() {
    vector<int> pushed = {
        1, 2, 3, 4, 5
    };

    vector<int> popped = {
        4, 5, 3, 2, 1
    };

    if (validateStackSequences(pushed, popped))
        cout << "Valid stack sequence" << endl;
    else
        cout << "Invalid stack sequence" << endl;

    return 0;
}
