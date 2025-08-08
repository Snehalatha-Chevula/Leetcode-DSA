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
    TreeNode* solve(TreeNode* root, TreeNode* right, TreeNode* left){
        if(root == NULL)
            return NULL;
        root->right = left;
        root->left = right;
        if(root->right){
            root->right = solve(root->right, root->right->right, root->right->left);
        }
        if(root->left){
            root->left = solve(root->left, root->left->right, root->left->left);
        }
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        return solve(root, root->right, root->left);
    }
};