#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> firstNegative(vector<int>& arr, int k) {
    queue<int> q;
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {

        if (arr[i] < 0)
            q.push(i);

        if (!q.empty() && q.front() <= i - k)
            q.pop();

        if (i >= k - 1) {
            if (q.empty())
                result.push_back(0);
            else
                result.push_back(arr[q.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {
        12, -1, -7, 8, -15, 30, 16, 28
    };

    int k = 3;

    vector<int> result = firstNegative(arr, k);

    for (int value : result)
        cout << value << " ";

    cout << endl;

    return 0;
}
