// LeetCode Question: 104 - Maximum Depth of Binary Tree
// Topics: Binary Tree, Recursion, Tree Traversal, DFS

class Solution {
private:
    int heightTree(TreeNode* root){
        if(root == NULL)
            return 0;
        int leftHeight = heightTree(root->left);
        int rightHeight = heightTree(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
public:
    int maxDepth(TreeNode* root) {
        return heightTree(root);
    }
};
