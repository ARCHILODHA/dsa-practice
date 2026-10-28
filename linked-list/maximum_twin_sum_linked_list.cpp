#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        int maximumSum = 0;
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            maximumSum = max(
                maximumSum,
                first->val + second->val
            );

            first = first->next;
            second = second->next;
        }

        return maximumSum;
    }
};
