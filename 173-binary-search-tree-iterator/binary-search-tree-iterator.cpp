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
class BSTIterator {
public:
    stack<TreeNode*> st;
    TreeNode* cur;
    BSTIterator(TreeNode* root) {
        while(!st.empty())
            st.pop();
        cur = root;
    }
    
    int next() {
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
        TreeNode* t = st.top();
        st.pop();
        cur = t->right;
        return t->val;
    }
    
    bool hasNext() {
        return cur || !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */