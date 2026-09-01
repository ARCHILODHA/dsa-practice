#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* previous;
    Node* next;

    Node(int value) {
        data = value;
        previous = nullptr;
        next = nullptr;
    }
};

// Insert at beginning
Node* insertAtBeginning(Node* head, int value) {

    Node* newNode = new Node(value);

    if (head != nullptr)
        head->previous = newNode;

    newNode->next = head;

    return newNode;
}

// Insert at end
Node* insertAtEnd(Node* head, int value) {

    Node* newNode = new Node(value);

    if (head == nullptr)
        return newNode;

    Node* temp = head;

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->previous = temp;

    return head;
}

// Delete a node
Node* deleteValue(Node* head, int value) {

    Node* temp = head;

    while (temp != nullptr &&
           temp->data != value) {
        temp = temp->next;
    }

    if (temp == nullptr)
        return head;

    if (temp->previous != nullptr)
        temp->previous->next = temp->next;
    else
        head = temp->next;

    if (temp->next != nullptr)
        temp->next->previous = temp->previous;

    delete temp;

    return head;
}

void displayForward(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void displayBackward(Node* head) {

    if (head == nullptr)
        return;

    while (head->next != nullptr)
        head = head->next;

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->previous;
    }

    cout << endl;
}

int main() {

    Node* head = nullptr;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    head = insertAtBeginning(head, 5);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    head = deleteValue(head, 20);

    cout << "After deletion: ";
    displayForward(head);

    return 0;
}
