class Solution {
public:
    bool valid(string &s,int target,int idx, int prevsum){
        if(idx == s.length())
            return prevsum == target;
        int cur = 0;
        for(int i=idx;i<s.length();i++){
            cur = (cur*10)+(s[i]-'0');
            if(valid(s,target,i+1,prevsum+cur))
                return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            int sq = i*i;
            string s = to_string(sq);
            if(valid(s,i,0,0))
                ans += sq;
        }
        return ans;
    }
};