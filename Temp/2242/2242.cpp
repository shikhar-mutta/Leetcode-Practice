// Link: https://leetcode.com/problems/maximum-score-of-a-node-sequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; i++) {
            sort(adj[i].begin(), adj[i].end(), [&](int a, int b) { return scores[a] > scores[b]; });
            if (adj[i].size() > 3) adj[i].resize(3);
        }

        int best = -1;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            for (int a : adj[x]) {
                if (a == y) continue;
                for (int b : adj[y]) {
                    if (b == x || b == a) continue;
                    int score = scores[a] + scores[x] + scores[y] + scores[b];
                    best = max(best, score);
                }
            }
        }
        return best;
    }
};
