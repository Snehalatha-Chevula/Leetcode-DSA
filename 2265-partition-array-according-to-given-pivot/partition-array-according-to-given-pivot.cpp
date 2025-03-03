class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int less=0,equal=0;
        for(auto x : nums){
            if(x < pivot)
                less++;
            else if(x == pivot)
                equal++;
        }
        vector<int> ans(nums.size());
        int p1=0, p2=less, p3=less+equal;
        for(auto x : nums){
            if(x < pivot){
                ans[p1] = x;
                p1++;
            }
            else if(x == pivot){
                ans[p2] = x;
                p2++;
            }
            else{
                ans[p3] = x;
                p3++;
            }
        }
        return ans;
    }
};