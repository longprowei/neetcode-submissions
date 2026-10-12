class Twitter {
private:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int tweetTime = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetTime++, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> maxHeap;
        following[userId].insert(userId);
        for (auto followee : following[userId]) {
            int postsNum = tweets.contains(followee) ? tweets[followee].size() : 0;
            if (postsNum > 0) {
                auto lastTweet = tweets[followee][postsNum - 1];
                maxHeap.emplace(lastTweet.first, lastTweet.second, followee, postsNum - 1);
            }
        }

        vector<int> res;
        while (!maxHeap.empty() && res.size() < 10) {
            auto [time, tweetId, followee, index] = maxHeap.top();
            maxHeap.pop();
            res.push_back(tweetId);
            if (index > 0) {
                index--;
                auto [newTime, newTweetId] = tweets[followee][index];
                maxHeap.emplace(newTime, newTweetId, followee, index);
            }
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
