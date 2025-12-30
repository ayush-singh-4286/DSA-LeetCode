// LeetCode Question: 543 - Diameter of Binary Tree
// Topics: Binary Tree, Recursion, DFS, Tree Height, Diameter Calculation

class Solution {
private:
    pair<int,int> diameterFast(TreeNode* root){
        // pair<int,int> = {diameter, height}
        if(root == NULL){
            return make_pair(0,0);
        }
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return diameterFast(root).first;
    }
};
