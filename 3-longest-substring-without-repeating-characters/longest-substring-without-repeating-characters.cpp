class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> myset;
        int i=0,j=0;
        int ans = 0;
        while(j < n){
            if(myset.count(s[j])){
                while(s[i] != s[j]){
                    myset.erase(s[i]);
                    i++;
                }
                i++;
                j++;
            }
            else{
                myset.insert(s[j]);
                j++;
                ans = max(ans,(int)myset.size());
            }
        }
        return ans;
    }
};