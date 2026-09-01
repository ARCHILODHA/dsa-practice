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

// Delete first node
Node* deleteFirst(Node* head) {
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
}

// Delete last node
Node* deleteLast(Node* head) {
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    Node* temp = head;

    while (temp->next->next != nullptr)
        temp = temp->next;

    delete temp->next;
    temp->next = nullptr;

    return head;
}

// Delete first occurrence of a value
Node* deleteValue(Node* head, int value) {
    if (head == nullptr)
        return nullptr;

    if (head->data == value)
        return deleteFirst(head);

    Node* temp = head;

    while (temp->next != nullptr &&
           temp->next->data != value) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    return head;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = deleteValue(head, 30);

    display(head);

    return 0;
}
