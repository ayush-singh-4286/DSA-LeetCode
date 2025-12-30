// LeetCode 222 - Count Complete Tree Nodes
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

class Solution {
private:
    void count(TreeNode* root, int &ans) {
        if(root == NULL)
            return;
        ans++;
        count(root->left, ans);
        count(root->right, ans);
    }

public:
    int countNodes(TreeNode* root) {
        int ans = 0;
        count(root, ans);
        return ans;
    }
};
