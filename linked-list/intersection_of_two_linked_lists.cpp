ListNode *getIntersectionNode(ListNode *a, ListNode *b) {
    ListNode *p1 = a, *p2 = b;

    while(p1 != p2) {
        p1 = p1 ? p1->next : b;
        p2 = p2 ? p2->next : a;
    }
    return p1;
}
