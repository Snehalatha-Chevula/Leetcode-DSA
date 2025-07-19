class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo = 0, hi = nums.size()-1, mini = nums[0];
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(nums[lo] <= nums[mid]){
                mini = min(mini,nums[lo]);
                lo = mid+1;
            }
            else{
                mini = min(mini,nums[mid]);
                hi = mid-1;
            }
        }
        return mini;
    }
};