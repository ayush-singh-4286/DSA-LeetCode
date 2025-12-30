// LeetCode 160 - Intersection of Two Linked Lists
// Topics: Linked List, Two Pointers, Hashing, Simulation

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        bool flag1 = true;
        bool flag2 = true;

        while(true){
            if(temp1 == NULL){
                if(flag1){
                    temp1 = headB;
                    flag1 = false;
                    continue;
                } else break;
            }

            if(temp2 == NULL){
                if(flag2){
                    temp2 = headA;
                    flag2 = false;
                    continue;
                } else break;
            }

            if(temp1 == temp2){
                break;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    }
};
