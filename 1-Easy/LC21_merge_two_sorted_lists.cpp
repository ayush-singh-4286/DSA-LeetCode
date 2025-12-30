// LeetCode Question 21: Merge Two Sorted Lists
// Topics: Linked List, Recursion, Iteration, Merge

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp3 = dummy;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1 != NULL && temp2 != NULL){
            if(temp1->val <= temp2->val){
                temp3->next = temp1;
                temp1 = temp1->next;
            }
            else{
                temp3->next = temp2;
                temp2 = temp2->next;
            }
            temp3 = temp3->next;
        }

        if(temp1 != NULL) temp3->next = temp1;
        if(temp2 != NULL) temp3->next = temp2;

        return dummy->next;
    }
};
