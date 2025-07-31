class Twitter {
public:
    vector<vector<bool>> followMat;
    unordered_map<int,vector<pair<int,int>>> mp;
    int time;
    Twitter() {
        mp.clear();
        followMat.resize(501,vector<bool>(501));
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<501;i++){
            if(followMat[userId][i] || userId == i)
                for(auto t : mp[i]){
                    pq.push(t);
                    if(pq.size() > 10)
                        pq.pop();
                }
        }
        vector<int> ans(pq.size());
        int i = pq.size()-1;
        while(!pq.empty()){
            ans[i] = pq.top().second;
            i--;
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followMat[followerId][followeeId] = true;
    }
    
    void unfollow(int followerId, int followeeId) {
        followMat[followerId][followeeId] = false;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */