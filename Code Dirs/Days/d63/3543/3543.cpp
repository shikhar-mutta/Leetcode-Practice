// Link: https://leetcode.com/problems/maximum-weighted-k-edge-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * E * t/64) SC: O(n * k * t/64)
// Approach: dp[v][e] is a bitset of achievable path sums using exactly e
// edges and ending at v, starting from any node. dp[v][0] = {0} for every
// v. For each edge count e (1..k), OR in dp[v][e] |= dp[u][e-1] << w for
// every edge (u,v,w); the bitset's fixed size naturally discards sums
// that overflow past the range we care about. The answer is the highest
// set bit below t across all dp[v][k].
class Solution {
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        const int CAP = 600;
        vector<vector<bitset<CAP>>> dp(n, vector<bitset<CAP>>(k + 1));
        for (int v = 0; v < n; v++) dp[v][0][0] = 1;

        for (int e = 1; e <= k; e++) {
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                dp[v][e] |= (dp[u][e-1] << w);
            }
        }

        int limit = min(t, CAP);
        for (int bit = limit - 1; bit >= 0; bit--) {
            for (int v = 0; v < n; v++) {
                if (dp[v][k][bit]) return bit;
            }
        }
        return -1;
    }
};
