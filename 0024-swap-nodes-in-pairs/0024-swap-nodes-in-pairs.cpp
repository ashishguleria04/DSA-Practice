class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* t = curr->next;
            curr->next = t->next;
            t->next = curr;
            prev->next = t;
            prev = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};