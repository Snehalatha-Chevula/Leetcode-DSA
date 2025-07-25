class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = INT_MIN;
        for(int i=0;i<=n;i++){
            while((i == n) || (!st.empty() && heights[i] < heights[st.top()])){
                if(st.empty())
                    break;
                int idx = st.top();
                st.pop();
                int lft = (st.empty() ? -1 : st.top());
                int width = i-lft-1;
                int height = heights[idx];
                ans = max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};