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

// Reverse the linked list
Node* reverse(Node* head) {
    Node* previous = nullptr;
    Node* current = head;

    while (current != nullptr) {
        Node* nextNode = current->next;

        current->next = previous;
        previous = current;
        current = nextNode;
    }

    return previous;
}

// Delete nodes having a greater value on the right
Node* deleteGreaterRight(Node* head) {

    head = reverse(head);

    int maximum = head->data;
    Node* current = head;

    while (current != nullptr &&
           current->next != nullptr) {

        if (current->next->data < maximum) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
            maximum = current->data;
        }
    }

    return reverse(head);
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next =
        new Node(2);
    head->next->next->next->next->next->next->next =
        new Node(3);

    head = deleteGreaterRight(head);

    display(head);

    return 0;
}
