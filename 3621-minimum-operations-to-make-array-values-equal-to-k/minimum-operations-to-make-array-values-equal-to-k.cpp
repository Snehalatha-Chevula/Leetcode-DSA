class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> myset;
        int greater = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>k && myset.find(nums[i]) == myset.end())
                greater++;
            else if(nums[i] < k)
                return -1;
            myset.insert(nums[i]);
        }
        return greater;
    }
};