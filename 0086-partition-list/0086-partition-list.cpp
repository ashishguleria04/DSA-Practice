class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;

        ListNode* smallerHead = new ListNode(0);
        ListNode* greaterEqualHead = new ListNode(0);
        ListNode* smallerTail = smallerHead;
        ListNode* greaterEqualTail = greaterEqualHead;

        ListNode* current = head;
        while (current) {
            if (current->val < x) {
                smallerTail->next = current;
                smallerTail = smallerTail->next;
            } else {
                greaterEqualTail->next = current;
                greaterEqualTail = greaterEqualTail->next;
            }
            current = current->next;
        }

        greaterEqualTail->next = nullptr; 
        smallerTail->next = greaterEqualHead->next; 

        return smallerHead->next;
    }
};