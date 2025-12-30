// LeetCode 530 - Minimum Absolute Difference in BST
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree

class Solution {
public:
// There is another approach
/*
    We can find the inorder and store it in a array and then
    use the index of the array to manipulte the mini value
    */
    int mini = INT_MAX;
    TreeNode* prev = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) return;

        inorder(root->left);

        if (prev != NULL) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mini;
    }
};
