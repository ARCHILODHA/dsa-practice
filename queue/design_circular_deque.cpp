#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque {
private:
    vector<int> data;
    int frontIndex;
    int rearIndex;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        data.resize(k);
        frontIndex = 0;
        rearIndex = -1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        frontIndex = (frontIndex - 1 + capacity) % capacity;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            frontIndex = (frontIndex - 1 + capacity) % capacity;
        }

        data[frontIndex] = value;
        count++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % capacity;
        }

        data[rearIndex] = value;
        count++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }

        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        rearIndex = (rearIndex - 1 + capacity) % capacity;
        count--;

        if (count == 0) {
            frontIndex = 0;
            rearIndex = -1;
        }

        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int getRear() {
        return isEmpty() ? -1 : data[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};
