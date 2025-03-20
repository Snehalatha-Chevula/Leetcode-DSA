class Solution {
public:
    int solve(vector<int>& prices, bool isbuy, int idx, int k, vector<vector<vector<int>>>& dp){
        if(k == 0 || idx == prices.size())
            return 0;
        if(dp[idx][k][isbuy] != -1)
            return dp[idx][k][isbuy];
        int include = 0, exclude = 0;
        if(isbuy){
            include = prices[idx] + solve(prices,false,idx+1,k-1,dp);
            exclude = solve(prices,true,idx+1,k,dp);
        }
        else{
            include = -prices[idx] + solve(prices,true,idx+1,k,dp);
            exclude = solve(prices,isbuy,idx+1,k,dp);
        }
        return dp[idx][k][isbuy] = max(include,exclude);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,false,0,1,dp);
    }
};