class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int lo = 0, hi = n-1;
        int ans = 0;
        if(arr[0] > k)
            return k;
        while(lo <= hi){
            int mid = (lo+(hi-lo)/2);
            int misNums = arr[mid] - (mid+1);
            if(misNums < k){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid - 1;
            }
        }
        int misNums = arr[ans] - (ans+1);
        return arr[ans]+(k-misNums);
    }
};