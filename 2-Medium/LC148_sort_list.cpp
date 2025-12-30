// LeetCode 148 - Sort List
// Topics: Linked List, Divide and Conquer, Recursion, Merge Sort

class Solution {
private:
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == NULL)
            return b;
        if(b == NULL)
            return a;
        if(a->val < b->val){
            a->next = merge(a->next, b);
            return a;
        }
        else{
            b->next = merge(a, b->next);
            return b;
        }
    }

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode* left = head;
        ListNode* mid = getMid(head);
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};
