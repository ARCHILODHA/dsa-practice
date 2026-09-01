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

// Search for a value
int search(Node* head, int target) {
    int position = 0;

    while (head != nullptr) {
        if (head->data == target)
            return position;

        head = head->next;
        position++;
    }

    return -1;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    int target = 30;

    int result = search(head, target);

    if (result != -1)
        cout << "Element found at position: "
             << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
