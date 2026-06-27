class Solution {
public:
    Node* removeDuplicates(Node* head) {
        unordered_set<int> st;

        Node* curr = head;
        Node* prev = nullptr;

        while (curr) {
            if (st.count(curr->data)) {
                prev->next = curr->next;
            } else {
                st.insert(curr->data);
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};
