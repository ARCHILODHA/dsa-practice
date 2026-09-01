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

void swapKthNodes(Node* head, int k) {
    int n = getLength(head);

    if (k > n)
        return;

    // kth node from beginning
    Node* first = head;

    for (int i = 1; i < k; i++)
        first = first->next;

    // kth node from end
    Node* second = head;

    for (int i = 1; i < n - k + 1; i++)
        second = second->next;

    swap(first->data, second->data);
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
    head->next->next->next->next = new Node(50);

    swapKthNodes(head, 2);

    display(head);

    return 0;
}
