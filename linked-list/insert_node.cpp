#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
};

// Insert a node at the beginning
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;

    return head;
}

// Insert a node at the end
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);

    if (head == nullptr)
        return newNode;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;

    return head;
}

// Insert after a given value
void insertAfter(Node* head, int target, int value) {
    Node* temp = head;

    while (temp != nullptr && temp->data != target)
        temp = temp->next;

    if (temp == nullptr) {
        cout << "Target not found\n";
        return;
    }

    Node* newNode = new Node(value);

    newNode->next = temp->next;
    temp->next = newNode;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = nullptr;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    head = insertAtBeginning(head, 5);

    insertAfter(head, 20, 25);

    display(head);

    return 0;
}
