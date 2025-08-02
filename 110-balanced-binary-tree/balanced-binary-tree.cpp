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
    int findHeight(TreeNode* root){
        if(root == NULL)
            return -1;
        return max(findHeight(root->left),findHeight(root->right))+1;
    }
    bool findBf(TreeNode* root){
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        cout <<lh <<" " <<rh <<endl;
        return (lh-rh >= -1) && (lh-rh <= 1);
    }
    bool inorder(TreeNode* root){
        if(root == NULL)
            return true;
        if(!findBf(root))
            return false;
        if(!inorder(root->left))
            return false;
        if(!inorder(root->right))
            return false;
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        return inorder(root);
    }
};