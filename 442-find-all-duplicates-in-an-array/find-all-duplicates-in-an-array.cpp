class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> myset;
        vector<int> ans;
        for(auto i : nums){
            if(myset.find(i) == myset.end())
                myset.insert(i);
            else
                ans.push_back(i);
        }
        return ans;
    }
};