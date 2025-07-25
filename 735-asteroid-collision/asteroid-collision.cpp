class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            bool isEqual = false;
            bool isLess = false;
            while(!st.empty() && ((asteroids[i]<0 && st.top()>0))){
                int curEle = abs(asteroids[i]);
                int topEle = abs(st.top());
                if(curEle == topEle){
                    isEqual = true;
                    st.pop();
                    break;
                }
                else if(curEle < topEle){
                    isLess = true;
                    break;
                }
                else{
                    st.pop();
                }
            }
            if(!isEqual && !isLess)
                st.push(asteroids[i]);
        }
        if(st.empty())
            return {};
        int len = st.size();
        vector<int> ans(len);
        for(int i=len-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};