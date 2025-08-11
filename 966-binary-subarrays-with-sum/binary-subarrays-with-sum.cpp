class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int prevz = 0;
        int ans = 0;
        int curSum = 0;
        int i = 0, j = 0;
        while(j < n){
            curSum += nums[j];
            while(i < j && (nums[i] == 0 || curSum > goal)){
                if(nums[i] == 0)
                    prevz++;
                else{
                    prevz = 0;
                    curSum -= nums[i];
                }
                i++;
            }
            if(curSum == goal){
                ans += (prevz + 1);
            }
            j++;
        }
        return ans;
    }
};