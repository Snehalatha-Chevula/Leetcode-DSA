/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root, int targetSum, int curSum){
        if((root && !root->left && !root->right && curSum+root->val == targetSum))
            return true;
        if(root == NULL){
            return false;
        }
        return solve(root->left, targetSum, curSum+root->val) || solve(root->right, targetSum, curSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return false;
        return solve(root, targetSum, 0);
    }
};