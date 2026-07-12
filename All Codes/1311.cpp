// Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m log m) where n is the number of friends and m is the number of videos watched by friends at the given level. We traverse the friends graph to find all friends at the given level, which takes O(n) time. Then we count the frequency of videos watched by those friends, which takes O(m) time. Finally, we sort the videos based on frequency and name, which takes O(m log m) time.
    // SC: O(n + m) for storing the seen friends and the frequency of videos
    //  Approach:
    //   1. Perform a BFS to find all friends at the given level from the starting friend (id).
    //   2. Count the frequency of videos watched by those friends
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        int n = friends.size();
        // BFS out to exactly `level` hops from id
        vector<bool> seen(n, false);
        vector<int> cur = {id};
        seen[id] = true;
        for (int d = 0; d < level; d++)
        {
            vector<int> nxt;
            for (int u : cur)
                for (int v : friends[u])
                    if (!seen[v])
                    {
                        seen[v] = true;
                        nxt.push_back(v);
                    }
            cur = move(nxt);
        }

        map<string, int> freq; // ordered: alphabetical tie-break for free
        for (int u : cur)
            for (auto &vid : watchedVideos[u])
                freq[vid]++;

        vector<pair<int, string>> order; // (frequency, name)
        for (auto &[vid, f] : freq)
            order.push_back({f, vid});
        stable_sort(order.begin(), order.end(),
                    [](const pair<int, string> &a, const pair<int, string> &b)
                    { return a.first < b.first; });

        vector<string> res;
        for (auto &[f, vid] : order)
            res.push_back(vid);
        return res;
    }
};
