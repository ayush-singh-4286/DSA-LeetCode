// LeetCode 653 - Two Sum IV - Input is a BST
// Topics: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Search Tree

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            int val = k - temp->val;
            if(s.count(val))
                return true;

            s.insert(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return false;
    }
};
