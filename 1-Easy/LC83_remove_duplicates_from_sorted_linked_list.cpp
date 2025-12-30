// LeetCode Question: 83. Remove Duplicates from Sorted List
// Topics: Linked List, Iteration, Pointers

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(temp == NULL || temp->next == NULL)
            return head;

        while(temp->next != NULL){
            if(temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};
