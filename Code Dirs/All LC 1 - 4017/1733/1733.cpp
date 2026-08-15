// Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> langSet(m + 1);
        for (int i = 0; i < m; i++) langSet[i+1] = unordered_set<int>(languages[i].begin(), languages[i].end());

        unordered_set<int> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool canCommunicate = false;
            for (int lang : langSet[u]) {
                if (langSet[v].count(lang)) { canCommunicate = true; break; }
            }
            if (!canCommunicate) { needTeach.insert(u); needTeach.insert(v); }
        }

        int best = INT_MAX;
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int u : needTeach) {
                if (!langSet[u].count(lang)) cnt++;
            }
            best = min(best, cnt);
        }
        return needTeach.empty() ? 0 : best;
    }
};
