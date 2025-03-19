class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums.size()-1;
        int ans=nums.size();
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(nums[mid]!=mid)
            { 
                if(nums[mid]<mid)
                {
                     ans=nums[mid]+1;
                     lo=mid+1;
                }
                else if(nums[mid]>mid)
                {
                    ans=nums[mid]-1;
                    hi=mid-1;
                }
                else
                  hi=mid-1;
            }
            else if(nums[mid]==mid)
              lo=mid+1;
            else
              hi=mid-1;
        }
        return ans;;
        
    }
};