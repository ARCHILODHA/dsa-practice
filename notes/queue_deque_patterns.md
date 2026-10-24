
# Queue and Deque Patterns

## 1. Introduction
A queue follows FIFO: First In, First Out.

A deque, or double-ended queue, supports insertion and removal at both ends.

## 2. C++ Queue
```cpp
queue<int> q;

q.push(10);
q.push(20);

cout << q.front();

q.pop();
