#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int>& q) {
    if(q.empty())
        return;

    int x = q.front();
    q.pop();

    reverseQueue(q);

    q.push(x);
}
