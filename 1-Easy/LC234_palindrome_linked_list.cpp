// LeetCode Question: 234 - Palindrome Linked List
// Topics: Linked List, Two Pointers, Fast & Slow Pointer, Reverse Linked List

class Solution {
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverse(slow);

        // Step 3: Compare halves
        ListNode* p1 = head;
        ListNode* p2 = secondHalf;
        bool pal = true;
        while (p2) {
            if (p1->val != p2->val) {
                pal = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        // Step 4: Restore list
        reverse(secondHalf);

        return pal;
    }
};
