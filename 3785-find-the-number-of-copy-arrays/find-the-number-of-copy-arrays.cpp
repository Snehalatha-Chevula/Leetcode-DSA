class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = original[i]-original[i-1];
            int upperbound = min(bounds[i][1]-diff,bounds[i-1][1]);
            int lowerbound = max(bounds[i-1][0],bounds[i][0]-diff);
            if(upperbound < bounds[i-1][0] || lowerbound > bounds[i-1][1])
                return 0;
            ans = min(ans,upperbound-lowerbound+1);
            bounds[i][0] = lowerbound+diff;
            bounds[i][1] = upperbound+diff;
        }
        return ans;
    }
};