class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
            return false;
        unordered_map<int,int> mp;
        for(int a : hand)
            mp[a]++;
        priority_queue<pair<int,int>> pq;
        for(auto i : mp){
            pq.push({i.first,i.second});
        }
        while(!pq.empty()){
            vector<pair<int,int>> remaining;
            int prev = pq.top().first;
            if(pq.top().second > 1)
                remaining.push_back({prev, pq.top().second-1});
            pq.pop();
            int s = groupSize-1;
            while(s){
                int cur = pq.top().first;
                if(cur != prev-1)
                    return false;
                if(pq.top().second > 1)
                    remaining.push_back({cur, pq.top().second-1});
                pq.pop();
                s--;
                prev = cur;
            }
            for(int i=0;i<remaining.size();i++)
                pq.push(remaining[i]);
        }
        return true;
    }
};