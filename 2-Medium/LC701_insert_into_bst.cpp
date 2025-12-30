// LeetCode 701 - Insert into a Binary Search Tree
// Topics: Tree, Binary Search Tree, Recursion

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int data) {
        
        if(root == NULL)
        {
            // Imp syntax to insert any node 
            return new TreeNode(data);
        }

        if(root->val > data)
            root->left = insertIntoBST(root->left, data);
        else
            root->right = insertIntoBST(root->right, data);

        // After insertion we have to return the root
        return root;
    }
};
