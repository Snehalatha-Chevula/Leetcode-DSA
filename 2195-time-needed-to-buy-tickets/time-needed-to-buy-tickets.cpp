class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        deque<pair<int,int>> dq;
        int time = 0;
        for(int i=0;i<n;i++)
            dq.push_back({tickets[i],i});
        while(!dq.empty()){
            if(dq.front().second == k && dq.front().first == 1)
                return time+1;
            dq.front().first--;
            time++;
            if(dq.front().first > 0)
                dq.push_back(dq.front());
            dq.pop_front();
        }
        return time;
    }
};