class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 1;
        int hi = accumulate(weights.begin(),weights.end(),0);
        int ans = hi;
        while(lo <= hi){
            int mid = (lo+(hi-lo)/2);
            if(isValid(weights,days,mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }

    bool isValid(vector<int>& weights, int days, int cap){
        int curCap = 0;
        for(int i=0;i<weights.size();i++){
            if(weights[i] > cap){
                return false;
            }
            curCap += weights[i];
            if(curCap == cap){
                days--;
                curCap = 0;
            }
            if(curCap > cap){
                curCap = weights[i];
                days--;
            }
            if(days < 0)
                return false;
        }
        if(curCap > 0)
            days--;
        return days >= 0;
    }
};