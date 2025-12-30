// LeetCode 138 - Copy List with Random Pointer
// Topics: Linked List, Hash Table, Simulation, Deep Copy

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        if(head == NULL)
            return head;

        // Step 1: Create copy nodes
        while(temp != NULL){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        // Step 2: Copy random pointers
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            temp = temp->next->next;
        }

        // Step 3: Separate the lists
        Node* newHead = head->next;
        temp = head;
        while(temp){
            Node* copy = temp->next;
            temp->next = copy->next;

            if(copy->next)
                copy->next = copy->next->next;

            temp = temp->next;
        }

        return newHead;
    }
};
