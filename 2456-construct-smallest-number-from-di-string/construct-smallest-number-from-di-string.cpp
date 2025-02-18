class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        vector<int> nums;
        string ans = "";
        int cur = 1;
        for(int i=0;i<=n;i++){
            nums.push_back(cur);
            cur++;
            if(i == n || pattern[i] == 'I'){
                while(!nums.empty()){
                    ans += to_string(nums.back());
                    nums.pop_back();
                }
            }
        }
        return ans;
    }
};