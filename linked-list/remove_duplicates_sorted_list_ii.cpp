#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {
            bool duplicate = false;

            while (curr->next &&
                   curr->val == curr->next->val) {
                ListNode* temp = curr;
                curr = curr->next;
                duplicate = true;
                delete temp;
            }

            if (duplicate) {
                ListNode* temp = curr;
                curr = curr->next;
                delete temp;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
