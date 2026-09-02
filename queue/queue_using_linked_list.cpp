#include <iostream>
using namespace std;

class Queue {
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = rearNode = nullptr;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
            return;
        }

        rearNode->next = newNode;
        rearNode = newNode;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
    }

    int front() {
        if (isEmpty())
            return -1;

        return frontNode->data;
    }

    void display() {
        Node* current = frontNode;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    cout << "Front: " << q.front() << endl;

    q.display();

    return 0;
}
