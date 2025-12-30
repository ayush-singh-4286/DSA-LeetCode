// LeetCode Question: 110 - Balanced Binary Tree
// Topics: Binary Tree, Recursion, DFS, Tree Height, Balanced Tree Check

class Solution {
private:
    pair<bool,int> balancedFast(TreeNode* root){
        if(root == NULL){
            return make_pair(true,0);
        }
        pair<bool,int> left = balancedFast(root->left);
        pair<bool,int> right = balancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.first = (leftAns && rightAns && diff);
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balancedFast(root).first;      
    }
};
