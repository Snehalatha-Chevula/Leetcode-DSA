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
    TreeNode* solve(vector<int>& pre, vector<int>& in, unordered_map<int,int>& mp, int lo, int hi, int& idx){
        if(lo > hi)
            return NULL;
        TreeNode* nn = new TreeNode(pre[idx]);
        int lidx = mp[pre[idx]];
        idx++;
        nn->left = solve(pre, in, mp, lo, lidx-1, idx);
        nn->right = solve(pre, in, mp, lidx+1, hi, idx);
        return nn;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n = inorder.size();
        for(int i=0;i<n;i++)
            mp[inorder[i]] = i;
        int idx = 0;
        return solve(preorder, inorder, mp, 0, n-1, idx);
    }
};