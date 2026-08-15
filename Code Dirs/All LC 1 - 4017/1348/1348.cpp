// Link: https://leetcode.com/problems/tweet-counts-per-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class TweetCounts {
public:
    unordered_map<string, vector<int>> times;

    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
        times[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int interval = (freq == "minute") ? 60 : (freq == "hour" ? 3600 : 86400);
        int buckets = (endTime - startTime) / interval + 1;
        vector<int> res(buckets, 0);
        for (int t : times[tweetName]) {
            if (t >= startTime && t <= endTime) {
                res[(t - startTime) / interval]++;
            }
        }
        return res;
    }
};
