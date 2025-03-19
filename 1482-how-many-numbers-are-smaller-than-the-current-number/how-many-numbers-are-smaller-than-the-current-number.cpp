class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        map<int,int> mp;
        for(auto ele : nums){
            mp[ele]++;
        }
        vector<int> ans;
        for(auto ele : nums){
            int cnt = 0;
            auto i = mp.begin();
            while(i != mp.end() && i->first != ele){
                cnt += i->second;
                i++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};