// Link: https://leetcode.com/problems/tweet-counts-per-frequency/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N). SC: O(N).
class TweetCounts
{
public:
    unordered_map<string, multiset<int>> mp;

    TweetCounts() {}

    void recordTweet(string tweetName, int time)
    {
        mp[tweetName].insert(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName,
                                           int startTime, int endTime)
    {
        int duration;
        if (freq == "minute")
            duration = 60;
        else if (freq == "hour")
            duration = 3600;
        else
            duration = 86400; // "day"

        int numChunks = (endTime - startTime) / duration + 1;
        vector<int> res(numChunks, 0);

        auto it = mp.find(tweetName);
        if (it == mp.end())
            return res; // chưa từng record
        const auto &times = it->second;

        // Chỉ duyệt các tweet rơi vào [startTime, endTime]
        auto lo = times.lower_bound(startTime);
        auto hi = times.upper_bound(endTime);
        for (auto t = lo; t != hi; ++t)
        {
            int idx = (*t - startTime) / duration;
            res[idx]++;
        }
        return res;
    }
};