class Solution {
public:
    int getSetPosition(long num){
        for(int i=0;i<32;i++){
            if((1<<i)&num)
                return i;
        }
        return 0;
    }
    vector<int> singleNumber(vector<int>& nums) {
        long x = 0;
        for(int i : nums)
            x ^= i;
        int zeroGroup = 0;
        int oneGroup = 0;
        int i = getSetPosition(x);
        for(int ele : nums){
            if((1<<i)&ele)
                oneGroup ^= ele;
            else
                zeroGroup ^= ele;
        }
        return {oneGroup,zeroGroup};
    }
};