// LeetCode 700 - Search in a Binary Search Tree
// Topics: Tree, Binary Search Tree, Recursion

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int data) {
        if(root == NULL)
            return NULL;

        if(root->val == data)
            return root;
        else if (root->val > data)
            return searchBST(root->left, data);
        else
            return searchBST(root->right, data);
    }
};
