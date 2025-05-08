class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> myset;
        for(int i=0;i<n;i++){
            if(myset.count(nums[i]))
                return true;
            else
                myset.insert(nums[i]);
        }
        return false;
    }
};