bool isPalindrome(ListNode* head) {
    vector<int> vals;

    while(head) {
        vals.push_back(head->val);
        head = head->next;
    }

    int i = 0, j = vals.size()-1;
    while(i < j) {
        if(vals[i++] != vals[j--]) return false;
    }
    return true;
}
