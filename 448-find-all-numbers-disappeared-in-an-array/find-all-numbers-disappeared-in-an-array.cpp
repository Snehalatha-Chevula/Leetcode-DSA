class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_set myset(nums.begin(),nums.end());
        for(int i=1;i<=n;i++){
            if(myset.find(i) == myset.end())
                ans.push_back(i);
        }
        return ans;
    }
};