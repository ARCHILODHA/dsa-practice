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

// Detect and remove loop using Floyd's algorithm
void removeLoop(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return;

    Node* slow = head;
    Node* fast = head;

    // Detect loop
    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (slow != fast)
        return;

    // Find start of loop
    slow = head;

    if (slow == fast) {
        while (fast->next != slow)
            fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    fast->next = nullptr;
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: 5 -> 3
    head->next->next->next->next->next =
        head->next->next;

    removeLoop(head);

    display(head);

    return 0;
}
