// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        unordered_map<string, int> id;
        auto getId = [&](const string& s) {
            auto it = id.find(s);
            if (it != id.end()) return it->second;
            int newId = id.size();
            id[s] = newId;
            return newId;
        };
        for (auto& s : original) getId(s);
        for (auto& s : changed) getId(s);
        int K = id.size();
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dist(K, vector<long long>(K, INF));
        for (int i = 0; i < K; i++) dist[i][i] = 0;
        for (int i = 0; i < (int)original.size(); i++) {
            int u = getId(original[i]), v = getId(changed[i]);
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < K; k++)
            for (int i = 0; i < K; i++)
                if (dist[i][k] < INF)
                    for (int j = 0; j < K; j++)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        set<int> lengths;
        for (auto& s : original) lengths.insert(s.size());
        for (auto& s : changed) lengths.insert(s.size());

        int n = source.size();
        vector<long long> dp(n + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= INF) continue;
            if (source[i] == target[i]) dp[i+1] = min(dp[i+1], dp[i]);
            for (int L : lengths) {
                if (i + L > n) continue;
                string subS = source.substr(i, L);
                string subT = target.substr(i, L);
                auto itS = id.find(subS);
                auto itT = id.find(subT);
                if (itS == id.end() || itT == id.end()) continue;
                long long d = dist[itS->second][itT->second];
                if (d < INF) dp[i+L] = min(dp[i+L], dp[i] + d);
            }
        }
        return dp[n] >= INF ? -1 : dp[n];
    }
};
