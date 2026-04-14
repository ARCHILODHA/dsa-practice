ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* curr = head;
    int count = 0;

    while(curr && count < k) {
        curr = curr->next;
        count++;
    }

    if(count == k) {
        curr = reverseKGroup(curr, k);
        while(count--) {
            ListNode* temp = head->next;
            head->next = curr;
            curr = head;
            head = temp;
        }
        head = curr;
    }
    return head;
}
