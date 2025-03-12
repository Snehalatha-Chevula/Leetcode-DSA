class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg = 0, zero = 0;
        for(int i=0;i<n;i++){
            if(nums[i] < 0)
                neg++;
            else if(nums[i] == 0)
                zero++;
            else
                break;
        }
        int pos = n -(neg+zero);
        return max(pos,neg);
    }
};