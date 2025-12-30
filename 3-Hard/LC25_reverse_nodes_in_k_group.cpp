// LeetCode 25 - Reverse Nodes in k-Group
// Topics: Linked List, Recursion, Data Structure

class Solution {
private:
    ListNode* reverse(ListNode* head, int k){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(k--){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check = head;
        for(int i = 0; i < k; i++){
            if(check == NULL)
                return head;
            else
                check = check->next;
        }

        ListNode* newhead = reverse(head, k);
        head->next = reverseKGroup(check, k);

        return newhead;
    }
};
