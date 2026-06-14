// Link: https://leetcode.com/problems/design-twitter/description/

#include <bits/stdc++.h>
using namespace std;

class Twitter
{
    int timer = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;   // userId → [(ts, tweetId)]
    unordered_map<int, unordered_set<int>> following;   // userId → {followeeIds}

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        // max-heap: (timestamp, tweetId, userId, index in tweets[userId])
        using T = tuple<int,int,int,int>;
        priority_queue<T> pq;

        auto push = [&](int uid) {
            auto& v = tweets[uid];
            if (!v.empty())
                pq.push({v.back().first, v.back().second, uid, (int)v.size()-1});
        };

        push(userId);
        for (int fid : following[userId]) push(fid);

        vector<int> res;
        while (!pq.empty() && (int)res.size() < 10) {
            auto [ts, tid, uid, idx] = pq.top(); pq.pop();
            res.push_back(tid);
            if (idx > 0) {
                auto& v = tweets[uid];
                pq.push({v[idx-1].first, v[idx-1].second, uid, idx-1});
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

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */