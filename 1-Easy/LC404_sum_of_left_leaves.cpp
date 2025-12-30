// LeetCode 404 - Sum of Left Leaves
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Tree

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;

        if(root->left == NULL && root->right == NULL)
            return 0;

        q.push(root);
        int ans = 0;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left) 
            {
                if(temp->left->left == NULL &&
                   temp->left->right == NULL)
                    ans += temp->left->val;

                q.push(temp->left);
            }
            if(temp->right)
                q.push(temp->right);
        }

        return ans;
    }
};
