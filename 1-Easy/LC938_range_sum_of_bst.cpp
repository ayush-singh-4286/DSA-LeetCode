// LeetCode 938 - Range Sum of BST
// Topics: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        int sum = low + high;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->val > low && temp->val < high){
                sum += temp->val;
            }

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        return sum;
    }
};
