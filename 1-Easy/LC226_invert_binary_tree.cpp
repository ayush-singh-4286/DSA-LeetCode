// LeetCode 226 - Invert Binary Tree
// Topics: Tree, Breadth-First Search, Binary Tree

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            swap(temp->left, temp->right);

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return root;
    }
};
