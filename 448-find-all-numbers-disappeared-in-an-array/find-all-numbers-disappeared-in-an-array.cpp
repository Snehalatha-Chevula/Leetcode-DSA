class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> myset;
        int n = nums.size();
        for(auto ele : nums){
            myset.insert(ele);
        }
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(myset.find(i) == myset.end())
                ans.push_back(i);
        }
        return ans;
    }
};