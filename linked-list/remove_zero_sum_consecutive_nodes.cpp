#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        unordered_map<int, ListNode*> prefix;
        int sum = 0;

        for (ListNode* curr = &dummy; curr;
             curr = curr->next) {
            sum += curr->val;
            prefix[sum] = curr;
        }

        sum = 0;

        for (ListNode* curr = &dummy; curr;
             curr = curr->next) {
            sum += curr->val;
            curr->next = prefix[sum]->next;
        }

        return dummy.next;
    }
};
