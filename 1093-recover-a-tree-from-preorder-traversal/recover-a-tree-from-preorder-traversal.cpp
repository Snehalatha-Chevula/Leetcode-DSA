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
    int idx = 0;
    TreeNode* recover(string &traversal,int dpth){
        if(idx == traversal.length())
            return NULL;
        int j = idx;
        while(traversal[j] == '-'){
            j++;
        }
        int dashes = j-idx;
        if(dashes != dpth)
            return NULL;
        int num = 0;
        while(j<traversal.length() && traversal[j] != '-'){
            num = num*10+(traversal[j]-'0');
            j++;
        }
        TreeNode* n = new TreeNode(num);
        idx = j;
        n->left = recover(traversal,dpth+1);
        n->right = recover(traversal,dpth+1);
        return n;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        return recover(traversal,0);
    }
};