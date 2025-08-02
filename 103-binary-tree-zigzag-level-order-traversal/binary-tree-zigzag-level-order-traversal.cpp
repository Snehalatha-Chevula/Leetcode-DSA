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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        deque<TreeNode*> dq;
        bool isOdd = true;
        dq.push_back(root);
        while(!dq.empty()){
            int s = dq.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                TreeNode* n = dq.front();
                dq.pop_front();
                temp.push_back(n->val);
                if(n->left)
                    dq.push_back(n->left);
                if(n->right)
                    dq.push_back(n->right);
            }
            if(isOdd)
                ans.push_back(temp);
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
            }
            isOdd = !isOdd;
        }
        return ans;
    }
};