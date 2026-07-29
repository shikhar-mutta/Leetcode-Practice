// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(V^3 + N*distinctLengths), SC: O(V^2 + N)
// Approach: build a graph over distinct substring "words" from original/changed with edge
// weights = cost, then Floyd-Warshall for all-pairs min transform cost. DP over source
// positions: dp[i] = min cost to convert source[0:i] to target[0:i]; from i, either the chars
// already match (free, advance by 1) or, for each known word length L, check if source[i:i+L]
// and target[i:i+L] are both known words with a finite transform cost.
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string,int> idx;
        auto getIdx = [&](const string& s) -> int {
            auto it = idx.find(s);
            if (it != idx.end()) return it->second;
            int id = idx.size();
            idx[s] = id;
            return id;
        };
        for (int i = 0; i < (int)original.size(); i++) { getIdx(original[i]); getIdx(changed[i]); }
        int V = idx.size();
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        for (int i = 0; i < V; i++) dist[i][i] = 0;
        for (int i = 0; i < (int)original.size(); i++) {
            int a = idx[original[i]], b = idx[changed[i]];
            dist[a][b] = min(dist[a][b], (long long)cost[i]);
        }
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        set<int> lengths;
        for (auto& w : original) lengths.insert(w.size());

        int n = source.size();
        vector<long long> dp(n+1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF) continue;
            if (source[i] == target[i]) dp[i+1] = min(dp[i+1], dp[i]);
            for (int L : lengths) {
                if (i + L > n) continue;
                string subS = source.substr(i, L);
                string subT = target.substr(i, L);
                auto itS = idx.find(subS);
                if (itS == idx.end()) continue;
                auto itT = idx.find(subT);
                if (itT == idx.end()) continue;
                long long c = dist[itS->second][itT->second];
                if (c < INF) dp[i+L] = min(dp[i+L], dp[i] + c);
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
    }
};
