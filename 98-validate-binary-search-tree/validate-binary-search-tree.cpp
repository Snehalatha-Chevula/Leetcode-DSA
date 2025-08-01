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
    bool validate(TreeNode* root, long a, long b){
        if(root == NULL)
            return true;
        return ((root->val > a && root->val < b) && (validate(root->left,a,root->val)) && (validate(root->right,root->val,b)));
    }
    bool isValidBST(TreeNode* root) {
        return validate(root,LONG_MIN,LONG_MAX);
    }
};