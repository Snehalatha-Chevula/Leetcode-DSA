class Solution {
public:
    bool valid(unordered_map<char,int>& mps, unordered_map<char,int>& mpt){
        for(auto i : mpt){
            char c = i.first;
            int freq = i.second;
            if(!mps.count(c) || mps[c] < freq)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char,int> mpt;
        for(char c : t)
            mpt[c]++;
        int i = 0, j = 0;
        string ans="";
        unordered_map<char,int> mps;
        while(j < n){
            mps[s[j]]++;
            while(i < j && (!mpt.count(s[i]) || mps[s[i]] > mpt[s[i]])){
                if(mps[s[i]] > 1)
                    mps[s[i]]--;
                else
                    mps.erase(s[i]);
                i++;
            }
            if(valid(mps,mpt)){
                if(ans == "" || ans.length() > j-i+1)
                    ans = s.substr(i,j-i+1);
            }
            j++;
        }
        return ans;
    }
};