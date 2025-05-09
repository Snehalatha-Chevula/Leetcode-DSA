class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> lft_min(n);
        vector<int> rgt_min(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty()){
                lft_min[i] = st.top();
            }
            else
                lft_min[i] = -1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if(!st.empty()){
                rgt_min[i] = st.top();
            }
            else
                rgt_min[i] = n;
            st.push(i);
        }
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int temp = heights[i]*(rgt_min[i]-lft_min[i]-1);
            ans = max(ans,temp);
        }
        return ans;
    }
};