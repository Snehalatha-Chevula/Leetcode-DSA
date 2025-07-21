class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *min_element(nums.begin(),nums.end());
        int hi = accumulate(nums.begin(),nums.end(),0);
        int ans = 0;
        while(lo <= hi){
            int mid = (lo+(hi-lo)/2);
            if(isValid(nums,k,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }

    bool isValid(vector<int>& nums, int k, int maxSum){
        int curSum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > maxSum)
                return false;
            curSum += nums[i];
            if(curSum == maxSum){
                cnt++;
                curSum = 0;
            }
            else if(curSum > maxSum){
                cnt++;
                curSum = nums[i];
            }
        }
        if(curSum > 0)
            cnt++;
        if(cnt <= k)
            return true;
        return false;
    }
};