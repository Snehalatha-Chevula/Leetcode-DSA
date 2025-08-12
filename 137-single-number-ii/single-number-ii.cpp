class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<32;i++){
            int setBits = 0;
            for(int j : nums){
                if((1<<i)&j)
                    setBits++;
            }
            if(setBits%3){
                ans += (1<<i);
            }
        }
        return ans;
    }
};