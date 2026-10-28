#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroup = &dummy;
        int groupSize = 1;

        while (prevGroup->next) {
            ListNode* groupStart = prevGroup->next;
            ListNode* curr = groupStart;
            int count = 0;

            while (curr && count < groupSize) {
                curr = curr->next;
                count++;
            }

            if (count % 2 == 0) {
                ListNode* prev = curr;
                ListNode* node = groupStart;

                for (int i = 0; i < count; i++) {
                    ListNode* nextNode = node->next;
                    node->next = prev;
                    prev = node;
                    node = nextNode;
                }

                prevGroup->next = prev;
                prevGroup = groupStart;
            } else {
                for (int i = 0; i < count; i++) {
                    prevGroup = prevGroup->next;
                }
            }

            groupSize++;
        }

        return dummy.next;
    }
};
