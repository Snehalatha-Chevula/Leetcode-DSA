class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int ans = 0;
        int curSum = 0;
        for(int i : nums){
            curSum += i;
            if(curSum == goal)
                ans++;
            if(mp.count(curSum-goal))
                ans += mp[curSum-goal];
            mp[curSum]++;
        }
        return ans;
    }
};