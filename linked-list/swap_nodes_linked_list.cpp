#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;

        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        ListNode* second = head;
        ListNode* fast = first;

        while (fast->next) {
            fast = fast->next;
            second = second->next;
        }

        swap(first->val, second->val);

        return head;
    }
};
