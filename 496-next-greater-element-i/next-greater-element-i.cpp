class Solution {
public:
    void findNge(vector<int>& nums2, vector<int>& nge){
        stack<int> st;
        int n = nums2.size();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();
            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(nums2[i]);
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> nge(n2);
        findNge(nums2,nge);
        unordered_map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]] = i;
        }
        int n1 = nums1.size();
        vector<int> ans(n1);
        for(int i=0;i<n1;i++){
            ans[i] = nge[mp[nums1[i]]];
        }
        return ans;
    }
};