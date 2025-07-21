class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int hi = *max_element(nums.begin(),nums.end());
        int ans = 0;
        while(lo <= hi){
            int mid = (lo +(hi-lo)/2);
            if(isValid(nums,threshold,mid)){
                ans = mid;
                hi = mid -1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }

    bool isValid(vector<int>& nums, int threshold, int mid){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid == 0)
                ans += (nums[i]/mid);
            else{
                ans += (nums[i]/mid);
                ans += 1;
            }
        }
        if(ans <= threshold)
            return true;
        return false;
    }
};