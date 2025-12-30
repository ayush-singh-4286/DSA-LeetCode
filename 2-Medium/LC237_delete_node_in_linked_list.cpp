// LeetCode Question: 237 - Delete Node in a Linked List
// Topics: Linked List, Pointer Manipulation, In-place Modification

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp = node;
        while(temp->next->next != NULL){
            temp->val = temp->next->val;
            temp = temp->next;
        }
        temp->val = temp->next->val;
        temp->next = NULL;
    }
};
