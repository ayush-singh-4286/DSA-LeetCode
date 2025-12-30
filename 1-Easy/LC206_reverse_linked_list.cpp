// LeetCode Question: 206 - Reverse Linked List
// Topics: Linked List, Recursion, Iterative Approach, Pointer Manipulation

class Solution {
private:
    ListNode* reverse(ListNode* temp, ListNode* curr){
        if(curr == NULL)
            return temp;

        ListNode* forward = curr->next;
        curr->next = temp;

        return reverse(curr, forward);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse(NULL, head);
    }
};
