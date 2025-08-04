class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int ans = INT_MIN;
        int cnt = k;
        while(j < n){
            if(nums[j] == 0){
                if(cnt)
                    cnt--;
                else{
                    while(i < j && nums[i] != 0)
                        i++;
                    i++;                      
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};