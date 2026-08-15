// Link: https://leetcode.com/problems/analyze-user-website-visit-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return timestamp[a] < timestamp[b]; });

        map<string, vector<string>> userSites;
        for (int i : idx) userSites[username[i]].push_back(website[i]);

        map<vector<string>, int> count;
        for (auto& [user, sites] : userSites) {
            set<vector<string>> seen;
            int m = sites.size();
            for (int i = 0; i < m; i++)
                for (int j = i + 1; j < m; j++)
                    for (int k = j + 1; k < m; k++)
                        seen.insert({sites[i], sites[j], sites[k]});
            for (auto& tri : seen) count[tri]++;
        }

        vector<string> best;
        int bestCount = 0;
        for (auto& [tri, c] : count) {
            if (c > bestCount) {
                bestCount = c;
                best = tri;
            }
        }
        return best;
    }
};
