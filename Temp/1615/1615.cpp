// Link: https://leetcode.com/problems/maximal-network-rank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> deg(n, 0);
        vector<vector<bool>> adj(n, vector<bool>(n, false));
        for (auto& r : roads) {
            deg[r[0]]++;
            deg[r[1]]++;
            adj[r[0]][r[1]] = adj[r[1]][r[0]] = true;
        }
        int best = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = deg[i] + deg[j] - (adj[i][j] ? 1 : 0);
                best = max(best, rank);
            }
        }
        return best;
    }
};
