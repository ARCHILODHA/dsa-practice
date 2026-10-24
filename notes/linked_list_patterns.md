
# Linked List Patterns

## 1. Introduction
A linked list consists of nodes containing data and pointers to other nodes.

Unlike arrays, linked-list nodes do not need to occupy contiguous memory.

## 2. Node Structure
```cpp
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};
3. Important Patterns
Fast and slow pointers
Reversing a linked list
Finding the middle node
Detecting cycles
Merging sorted linked lists
Removing the Nth node from the end
Using a dummy node
4. Reverse a Linked List
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

Time Complexity: O(N)

Space Complexity: O(1)

5. Find the Middle Node
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
6. Detect a Cycle

Use Floyd's Cycle Detection Algorithm.

Slow pointer moves one step.
Fast pointer moves two steps.
If they meet, a cycle exists.

Time Complexity: O(N)

Space Complexity: O(1)

7. Practice Problems
Reverse Linked List
Linked List Cycle
Middle of the Linked List
Merge Two Sorted Lists
Remove Nth Node From End
Reorder List
Add Two Numbers
8. Common Mistakes
Losing the next pointer during reversal
Incorrect handling of empty lists
Dereferencing nullptr
Forgetting to update the head
Failing to handle single-node lists
9. Key Takeaway

Pointer manipulation is the foundation of linked-list problem solving.
