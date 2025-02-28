class Solution {
public:
    int memoi(string &s1,string &s2,int i,int j,vector<vector<int>> &dp){
        if(i==s1.length() || j==s2.length())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            dp[i][j] = memoi(s1,s2,i+1,j+1,dp)+1;
        else
            dp[i][j] = max(memoi(s1,s2,i+1,j,dp),memoi(s1,s2,i,j+1,dp));
        return dp[i][j];
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length();
        int n2 = str2.length();
        string ans="";
        vector<vector<int>> dp(n1,vector<int>(n2,-1));
        memoi(str1,str2,0,0,dp);
        int i=0, j=0;
        while(i < n1 && j< n2){
            if(str1[i] == str2[j]){
                ans += str1[i];
                i++;
                j++;
            }
            else{
                if(j+1<n2 && i+1<n1){
                    if(dp[i+1][j] >= dp[i][j+1]){
                        ans += str1[i];
                        i++;
                    }
                    else{
                        ans += str2[j];
                        j++;
                    }
                }
                else if(j+1>=n2 && i+1>=n1){
                    ans += str1[i];
                    ans += str2[j];
                    i++;
                    j++;
                    break;
                }
                else if(j+1 >= n2){
                    ans += str1[i];
                    i++;
                }
                else{
                    ans += str2[j];
                    j++;
                }
            }
        }
        while(i < n1){
            ans += str1[i];
            i++;
        }
        while(j < n2){
            ans += str2[j];
            j++;
        }
        return ans;
    }
};