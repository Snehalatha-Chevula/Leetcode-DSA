class Solution {
public:
    char solve(string ans, int n, int k){
        if(ans.length() >= k)
            return ans[k-1];
        int s = ans.length();
        ans += '1';
        for(int i=s-1;i>=0;i--){
            if(ans[i] == '0')
                ans += '1';
            else
                ans += '0';
        }
        return solve(ans,n-1,k);
    }
    char findKthBit(int n, int k) {
        return solve("0",n-1,k);
    }
};