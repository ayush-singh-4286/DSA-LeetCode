// LeetCode Question: 24. Swap Nodes in Pairs
// Topics: Linked List, Recursion, Iteration

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr && curr->next != nullptr) {
            ListNode* first = curr;
            ListNode* second = curr->next;

            // swap
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // move pointers ahead
            prev = first;
            curr = first->next;
        }

        return dummy->next;
    }
};
