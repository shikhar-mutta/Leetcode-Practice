// Link: https://leetcode.com/problems/maximum-weighted-k-edge-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const int MAXSUM = 600;
    vector<vector<pair<int,int>>> adj;
    vector<vector<bitset<MAXSUM>>> memo;
    vector<vector<char>> computed;

    bitset<MAXSUM> dp(int node, int remaining) {
        if (remaining == 0) {
            bitset<MAXSUM> r;
            r.set(0);
            return r;
        }
        if (computed[node][remaining]) return memo[node][remaining];
        computed[node][remaining] = 1;
        bitset<MAXSUM> result;
        for (auto& [v, w] : adj[node]) {
            bitset<MAXSUM> child = dp(v, remaining - 1);
            result |= (child << w);
        }
        memo[node][remaining] = result;
        return result;
    }

    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        adj.assign(n, {});
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        memo.assign(n, vector<bitset<MAXSUM>>(k + 1));
        computed.assign(n, vector<char>(k + 1, 0));

        bitset<MAXSUM> all;
        for (int node = 0; node < n; node++) all |= dp(node, k);

        int cap = min(t, MAXSUM);
        for (int s = cap - 1; s >= 0; s--) {
            if (all.test(s)) return s;
        }
        return -1;
    }
};
