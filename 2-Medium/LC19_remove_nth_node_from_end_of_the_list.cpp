// LeetCode Question: 19 - Remove Nth Node From End of List
// Topics: Linked List, Two Pointers, List Traversal

class Solution {
    private:
    int findLen(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count+=1;
            temp=temp->next;
        }
        return count;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length=findLen(head);
        int count=length-n;
        if(n == length){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        int tryCount=0;
        ListNode* temp=head;
        while(temp!=NULL){
            tryCount++;
            if(tryCount == count){
                ListNode* deleteNode=temp->next;
                temp->next=temp->next->next;
                delete deleteNode;
                // Ye mere dimag me nhi aaya tha
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
