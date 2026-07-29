// Link: https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*14), SC: O(N*14)
// Approach: tree DP with a "halving level" h (0..13, since coins <= 1e4 < 2^14 so beyond that
// halving further changes nothing). dp(u,h) = max of: taking (coins[u]>>h)-k with children at
// the same level, or taking (coins[u]>>h)/2 and bumping all descendants to level h+1.
class Solution {
public:
    vector<vector<int>> adj;
    vector<int>* coins;
    int K;
    vector<vector<int>> memo;

    int dp(int u, int p, int h) {
        if (h >= 13) h = 13;
        if (memo[u][h] != -1) return memo[u][h];
        int val = (*coins)[u] >> h;

        long long option1 = (long long)val - K;
        for (int v : adj[u]) if (v != p) option1 += dp(v, u, h);

        long long option2 = val / 2;
        int nh = min(h+1, 13);
        for (int v : adj[u]) if (v != p) option2 += dp(v, u, nh);

        int best = (int)max(option1, option2);
        memo[u][h] = best;
        return best;
    }

    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins_, int k) {
        int n = coins_.size();
        adj.assign(n, {});
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        coins = &coins_;
        K = k;
        memo.assign(n, vector<int>(14, -1));
        return dp(0, -1, 0);
    }
};
