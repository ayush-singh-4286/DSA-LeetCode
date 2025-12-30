// LeetCode Question: 141 - Linked List Cycle
// Topics: Linked List, Cycle Detection, Floyd's Tortoise and Hare, Two Pointers

class Solution {
private:
    bool isCycle(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow)
                return true;
        }
        return false;
    }
public:
    bool hasCycle(ListNode *head) {
        return isCycle(head);
    }
};
