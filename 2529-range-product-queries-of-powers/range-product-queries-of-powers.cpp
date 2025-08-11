class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> powers;
        int m = 1e9+7;
        int i = 0;
        while(n > 0){
            if(n & 1){
                powers.push_back(1<<i);
            }
            i++;
            n = n>>1;
        }
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            long prod = 1;
            for(i=l;i<=r;i++)
                prod = (prod*powers[i])%m;
            ans.push_back(prod);
        }
        return ans;
    }
};