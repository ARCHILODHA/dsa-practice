#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

int getLength(Node* head) {
    int length = 0;

    while (head != nullptr) {
        length++;
        head = head->next;
    }

    return length;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Length: " << getLength(head) << endl;

    return 0;
}
