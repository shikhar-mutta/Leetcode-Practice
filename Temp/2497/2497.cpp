// Link: https://leetcode.com/problems/maximum-star-sum-of-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(vals[e[1]]);
            adj[e[1]].push_back(vals[e[0]]);
        }

        int best = INT_MIN;
        for (int i = 0; i < n; i++) {
            sort(adj[i].rbegin(), adj[i].rend());
            long long sum = vals[i];
            for (int j = 0; j < min(k, (int)adj[i].size()); j++) {
                if (adj[i][j] > 0) sum += adj[i][j];
                else break;
            }
            best = max(best, (int)sum);
        }
        return best;
    }
};
