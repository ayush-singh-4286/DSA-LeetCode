// LeetCode Question: 142 - Linked List Cycle II
// Topics: Linked List, Cycle Detection, Floyd's Tortoise and Hare, Two Pointers

class Solution {
private:
    ListNode* floydcycledetection(ListNode* head){
        if(head == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != NULL && fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
            }
            slow = slow->next;
            if(slow == fast){
                return slow;
            }     
        }
        return NULL;
    }

    ListNode* getStarting(ListNode* head){
        ListNode* intersection = floydcycledetection(head);
        if(intersection == NULL)
            return NULL;
        ListNode* slow = head;
        while(slow != intersection){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }

public:
    ListNode *detectCycle(ListNode *head) {
        return getStarting(head);
    }
};
