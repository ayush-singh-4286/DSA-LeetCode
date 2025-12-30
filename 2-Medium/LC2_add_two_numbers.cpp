// LeetCode Question 2: Add Two Numbers
// Topics: Linked List, Math, Simulation

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        
        while(l1 != NULL || l2 != NULL || carry != 0) {
            int x = (l1 != NULL) ? l1->val : 0;
            int y = (l2 != NULL) ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            int finalSum = sum % 10;
            
            tail->next = new ListNode(finalSum);
            tail = tail->next;

            if(l1 != NULL) l1 = l1->next;
            if(l2 != NULL) l2 = l2->next;
        }
        
        return dummy->next;
    }
};


