class Solution {
public:
    Node* divide(Node* head) {

        Node evenDummy(0), oddDummy(0);
        Node *even = &evenDummy, *odd = &oddDummy;

        while (head) {
            if (head->data % 2 == 0) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
        }

        even->next = oddDummy.next;
        odd->next = nullptr;

        return evenDummy.next;
    }
};
