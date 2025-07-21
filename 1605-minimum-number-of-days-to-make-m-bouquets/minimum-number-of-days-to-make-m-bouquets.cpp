class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = *min_element(bloomDay.begin(),bloomDay.end());
        int hi = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(isValid(bloomDay,m,k,mid)){
                ans = mid;
                hi = mid-1;
            }
            else
                lo = mid+1;
        }
        return ans;
    }

    bool isValid(vector<int>& bloomDay, int m, int k, int mid){
        int n = bloomDay.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(bloomDay[i] <= mid){
                cnt++;
            }
            else
                cnt = 0;
            if(cnt == k){
                m--;
                cnt = 0;
            }
            if(m == 0)
                return true;
        }
        //return (m == 0);
        return false;
    }
};