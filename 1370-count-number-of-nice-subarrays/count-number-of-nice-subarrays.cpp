class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int prevEven = 0;
        int odds = 0;
        int ans = 0;
        int i = 0, j = 0;
        while(j < n){
            if(nums[j]%2)
                odds++;
            while(i < j && (nums[i]%2 == 0 || odds > k)){
                if(nums[i]%2 == 0)
                    prevEven++;
                else{
                    prevEven = 0;
                    odds--;
                }
                i++;
            }
            if(odds == k)
                ans += (prevEven + 1);
            j++;
        }
        return ans;
    }
};