#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

class FirstUnique {
    queue<int> q;
    unordered_map<int, int> frequency;

public:
    void add(int value) {
        frequency[value]++;
        q.push(value);
    }

    int getFirstUnique() {
        while (!q.empty() && frequency[q.front()] > 1)
            q.pop();

        if (q.empty())
            return -1;

        return q.front();
    }
};

int main() {
    FirstUnique obj;

    obj.add(2);
    obj.add(3);
    obj.add(5);
    obj.add(2);

    cout << "First unique: " << obj.getFirstUnique() << endl;

    obj.add(3);

    cout << "First unique: " << obj.getFirstUnique() << endl;

    return 0;
}
