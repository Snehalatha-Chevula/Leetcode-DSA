class Solution {
public:
    long long solve(vector<vector<int>>& questions, int idx, int n, vector<long long>& dp){
        if(idx >= n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        return dp[idx] = max(solve(questions,idx+1,n,dp),solve(questions,idx+questions[idx][1]+1,n,dp)+questions[idx][0]);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return solve(questions,0,n,dp);
    }
};