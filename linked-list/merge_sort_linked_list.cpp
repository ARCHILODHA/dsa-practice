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

// Merge two sorted lists
Node* mergeLists(Node* first, Node* second) {

    if (first == nullptr)
        return second;

    if (second == nullptr)
        return first;

    if (first->data <= second->data) {
        first->next =
            mergeLists(first->next, second);

        return first;
    }

    second->next =
        mergeLists(first, second->next);

    return second;
}

// Find middle node
Node* getMiddle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Merge sort
Node* mergeSort(Node* head) {

    if (head == nullptr ||
        head->next == nullptr)
        return head;

    Node* middle = getMiddle(head);

    Node* second = middle->next;
    middle->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(second);

    return mergeLists(left, right);
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(40);
    head->next = new Node(10);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20);
    head->next->next->next->next =
        new Node(50);

    head = mergeSort(head);

    display(head);

    return 0;
}
