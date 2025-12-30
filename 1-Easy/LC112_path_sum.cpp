// LeetCode Question: 112. Path Sum
// Topics: Binary Tree, Recursion, DFS

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;

        if(root->left == NULL && root->right == NULL){
            if(targetSum == root->val)
                return true;
            else
                return false;
        }

        bool leftPos = hasPathSum(root->left, targetSum - root->val);
        bool rightPos = hasPathSum(root->right, targetSum - root->val);

        if(leftPos || rightPos)
            return true;
        else
            return false;
    }
};
