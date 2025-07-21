class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(mid-1 < 0 && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid+1 > n && nums[mid] != nums[mid-1])
                return nums[mid];
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid%2 == 0 && nums[mid+1] == nums[mid])
                lo = mid+1;
            else if(mid%2 != 0 && nums[mid-1] == nums[mid])
                lo = mid +1;
            else
                hi = mid-1;
        }
        return 0;
    }
};