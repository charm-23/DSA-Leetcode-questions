class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>>posts; 
    unordered_map<int, set<int>>following; 
    int timestamp=0; 

    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timestamp, tweetId}); 
        timestamp++; 
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>maxh; 
        vector<int>ans; 

        for(auto &i: posts[userId]){
            maxh.push(i); 
        }
        for(auto &i: following[userId]){
            for(auto &j: posts[i]){
                maxh.push(j); 
            }
        }

        int k=0; 
        while(!maxh.empty() && k<10){
            ans.push_back(maxh.top().second); 
            maxh.pop(); 
            k++; 
        }
        return ans; 
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId); 
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId); 
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