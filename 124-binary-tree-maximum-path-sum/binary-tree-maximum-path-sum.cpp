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
    int ans = INT_MIN;

    int maxSumPath1(TreeNode* root){
        if(root == NULL)    
            return 0;
        int left = max(maxSumPath1(root->left),0);
        int right = max(maxSumPath1(root->right),0);
        int curr = left + right + root->val;
        ans = max(ans, curr);
        curr = max(left,right)+root->val;
        return curr;
    }

    int maxPathSum(TreeNode* root) {
        maxSumPath1(root);
        return ans;
    }
};