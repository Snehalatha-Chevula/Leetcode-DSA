class Solution {
public:
    bool isValid(vector<bool>& avbl, int n){
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                if(avbl[i])
                    return false;
            }
        }
        return true;
    }
    void addbits(vector<bool>& avbl, int n){
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                avbl[i] = true;
            }
        }
    }
    void removebits(vector<bool>& avbl, int n){
        for(int i=0;i<32;i++){
            if((n>>i)&1){
                avbl[i] = false;
            }
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<bool> avbl(32,false);
        int st=0, end=0;
        while(end < n){
            while(!(isValid(avbl,nums[end]))){
                removebits(avbl,nums[st]);
                st++;
            }
            addbits(avbl,nums[end]);
            ans = max(ans,end-st+1);
            end++;
        }
        return ans;
    }
};