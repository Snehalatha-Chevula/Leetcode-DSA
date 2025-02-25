class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int m = 1e9+7;
        int n = arr.size();
        vector<long long> prefix(n);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++)
            prefix[i] = (arr[i]+prefix[i-1])%m;
        int prev_odd = 0;
        int prev_even = 0;
        long ans = 0;
        for(int i=0;i<n;i++){
            long long sum = prefix[i];
            if(sum%2 != 0){
                ans++;
                ans += prev_even;
                prev_odd++;
            }
            else if(sum%2 == 0){
                ans += prev_odd;
                prev_even++;
            }
        }
        return ans%m;
    }
};