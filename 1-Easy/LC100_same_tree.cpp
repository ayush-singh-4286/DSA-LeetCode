// LeetCode Question: 100 - Same Tree
// Topics: Binary Tree, Recursion, Tree Comparison, DFS

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL )
            return true;

        if(p != NULL && q == NULL)
            return false;
        
        if(p == NULL && q != NULL)
            return false;

        bool leftCorrect = isSameTree(p->left, q->left);
        bool rightCorrect = isSameTree(p->right, q->right);
        bool valueCorrect = (p->val == q->val);

        if(valueCorrect && leftCorrect && rightCorrect)
            return true;
        else
            return false;
    }
};
