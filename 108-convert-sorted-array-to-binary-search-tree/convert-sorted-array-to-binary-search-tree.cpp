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
    TreeNode* insertNode(vector<int>& nums, int lo, int hi){
        if(lo > hi)
            return NULL;
        int mid = (lo+hi)/2;
        TreeNode* nn = new TreeNode(nums[mid]);
        nn->left = insertNode(nums,lo,mid-1);
        nn->right = insertNode(nums,mid+1,hi);
        return nn;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insertNode(nums,0,nums.size()-1);
    }
};