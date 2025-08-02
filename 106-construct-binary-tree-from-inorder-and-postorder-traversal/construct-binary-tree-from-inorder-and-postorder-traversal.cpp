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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,unordered_map<int,int>&inorder_mp,int lo,int hi, int& idx){
        if(lo > hi)
            return NULL;
        TreeNode* nn = new TreeNode(postorder[idx]);
        int l_idx = inorder_mp[postorder[idx]];
        idx--;
        nn->right = solve(inorder,postorder,inorder_mp,l_idx+1,hi,idx);
        nn->left = solve(inorder,postorder,inorder_mp,lo,l_idx-1,idx);
        return nn;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorder_mp;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            inorder_mp[inorder[i]] = i;
        }
        int idx = n-1;
        return solve(inorder,postorder,inorder_mp,0,n-1,idx);
    }
};