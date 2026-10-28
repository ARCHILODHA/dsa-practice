#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeInBetween(
        ListNode* list1,
        int a,
        int b,
        ListNode* list2
    ) {
        ListNode* beforeA = list1;

        for (int i = 0; i < a - 1; i++) {
            beforeA = beforeA->next;
        }

        ListNode* afterB = beforeA;

        for (int i = 0; i < b - a + 2; i++) {
            afterB = afterB->next;
        }

        beforeA->next = list2;

        ListNode* tail = list2;

        while (tail->next) {
            tail = tail->next;
        }

        tail->next = afterB;

        return list1;
    }
};
