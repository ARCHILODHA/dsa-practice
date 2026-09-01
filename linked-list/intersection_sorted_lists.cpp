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

// Find intersection of two sorted linked lists
Node* intersection(Node* head1, Node* head2) {
    Node* result = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr &&
           head2 != nullptr) {

        if (head1->data == head2->data) {

            Node* newNode = new Node(head1->data);

            if (result == nullptr) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            head1 = head1->next;
            head2 = head2->next;
        }
        else if (head1->data < head2->data) {
            head1 = head1->next;
        }
        else {
            head2 = head2->next;
        }
    }

    return result;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(4);
    head1->next->next->next = new Node(6);

    Node* head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);

    Node* result = intersection(head1, head2);

    display(result);

    return 0;
}
