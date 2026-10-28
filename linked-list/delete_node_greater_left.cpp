#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteNodes(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        int maxValue = head->val;
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->next->val < maxValue) {
                ListNode* temp = curr->next;
                curr->next = temp->next;
                delete temp;
            } else {
                curr = curr->next;
                maxValue = curr->val;
            }
        }

        return head;
    }
};
