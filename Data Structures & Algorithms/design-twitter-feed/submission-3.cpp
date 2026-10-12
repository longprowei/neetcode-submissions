class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, unordered_set<int>> followed;
    unordered_map<int, set<pair<int, int>>> tweets;
    unordered_map<int, set<pair<int, int>> >newsFeed;
    int tweetTime = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace(tweetTime, tweetId);
        newsFeed[userId].emplace(tweetTime, tweetId);
        for (auto user : followed[userId]) {
            newsFeed[user].emplace(tweetTime, tweetId);
        }
        tweetTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> tweets;

        int i = 0;
        for (auto it = newsFeed[userId].rbegin(); it != newsFeed[userId].rend() && i < 10; it++, i++) {
            tweets.push_back(it->second);
        }
        return tweets;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
        followed[followeeId].insert(followerId);
        for (auto p : tweets[followeeId]) {
            newsFeed[followerId].insert(p);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
        followed[followeeId].erase(followerId);
        for (auto p : tweets[followeeId]) {
            newsFeed[followerId].erase(p);
        }
    }
};
