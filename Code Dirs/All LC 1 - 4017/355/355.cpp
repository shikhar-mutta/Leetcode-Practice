// Link: https://leetcode.com/problems/design-twitter/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(t log t) getNewsFeed where t = tweets from followees  SC: O(users + tweets)
// Approach: each user keeps a list of (timestamp, tweetId); getNewsFeed merges
// self + followees' tweets via a max-heap, keeping the 10 most recent
class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int,int>>> tweets; // userId -> [(time, tweetId)]
    unordered_map<int, unordered_set<int>> following;  // userId -> set of followees

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int,int>> heap; // (time, tweetId) - stores indices instead below
        vector<int> res;
        // use a heap over pointers into each user's tweet list (most recent first)
        priority_queue<tuple<int,int,int>> pq; // (time, tweetId, listIdx position)
        vector<int> userIds(following[userId].begin(), following[userId].end());
        userIds.push_back(userId);

        vector<int> ptr(userIds.size());
        for (int i = 0; i < (int)userIds.size(); i++) {
            auto& list = tweets[userIds[i]];
            ptr[i] = list.size() - 1;
            if (ptr[i] >= 0) pq.push({list[ptr[i]].first, list[ptr[i]].second, i});
        }

        while (!pq.empty() && (int)res.size() < 10) {
            auto [t, tid, i] = pq.top(); pq.pop();
            res.push_back(tid);
            ptr[i]--;
            if (ptr[i] >= 0) {
                auto& list = tweets[userIds[i]];
                pq.push({list[ptr[i]].first, list[ptr[i]].second, i});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
