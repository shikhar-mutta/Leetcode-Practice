// Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>> dist(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        for (int i = 0; i < (int)original.size(); i++) {
            int u = original[i] - 'a', v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        long long total = 0;
        for (int i = 0; i < (int)source.size(); i++) {
            int u = source[i] - 'a', v = target[i] - 'a';
            if (dist[u][v] >= INF) return -1;
            total += dist[u][v];
        }
        return total;
    }
};
