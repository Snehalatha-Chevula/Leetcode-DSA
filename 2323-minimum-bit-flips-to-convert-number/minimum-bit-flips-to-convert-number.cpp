class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = 0;
        int val = start ^ goal;
        while(val){
            ans++;
            val = (val&(val-1));
        }
        return ans;
    }
};