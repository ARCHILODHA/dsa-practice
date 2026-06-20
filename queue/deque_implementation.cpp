#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_front(10);
    dq.push_back(20);

    cout << dq.front() << endl;
    cout << dq.back() << endl;
}
