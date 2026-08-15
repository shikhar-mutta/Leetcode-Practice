// Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        visited[id] = true;
        queue<int> q;
        q.push(id);
        int curLevel = 0;
        vector<int> curLevelPeople;
        while (!q.empty() && curLevel < level) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front(); q.pop();
                for (int v : friends[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            curLevel++;
        }

        unordered_map<string,int> freq;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto& video : watchedVideos[u]) freq[video]++;
        }

        vector<string> res;
        for (auto& [v, c] : freq) res.push_back(v);
        sort(res.begin(), res.end(), [&](const string& a, const string& b) {
            if (freq[a] != freq[b]) return freq[a] < freq[b];
            return a < b;
        });
        return res;
    }
};
