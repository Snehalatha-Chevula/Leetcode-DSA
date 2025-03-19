class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for(auto ele : nums){
            if(myset.find(ele)!=myset.end())
                return true;
            myset.insert(ele);
        }
        return false;
    }
};