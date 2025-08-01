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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while(!dq.empty()){
            int s = dq.size();
            vector<int> cur;
            for(int i=0;i<s;i++){
                TreeNode* temp = dq.front();
                dq.pop_front();
                cur.push_back(temp->val);
                if(temp->left != NULL)
                    dq.push_back(temp->left);
                if(temp->right != NULL)
                    dq.push_back(temp->right);
            }
            ans.push_back(cur);
        }
        return ans;
    }
};