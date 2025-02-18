class Solution {
public:
    int reverse(int x) {
        if(x <= INT_MIN || x >= INT_MAX)
            return 0;
        bool neg = false;
        if(x < 0){
            neg = true;
            x *= (-1);
        }
        string s = to_string(x);
        s = string(s.rbegin(),s.rend());
        long ans = stol(s);
        if(neg)
            ans *= (-1);
        if(ans<=INT_MIN || ans>=INT_MAX)
            return 0;
        return ans;
    }
};