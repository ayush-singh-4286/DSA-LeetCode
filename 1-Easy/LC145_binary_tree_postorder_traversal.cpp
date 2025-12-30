// LeetCode Question: 145 - Binary Tree Postorder Traversal
// Topics: Binary Tree, Recursion, Tree Traversal, DFS, Postorder

class Solution {
private:
    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL)
            return;
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }
};
