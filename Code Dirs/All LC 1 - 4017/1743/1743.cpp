// Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        for (auto& p : adjacentPairs) {
            adj[p[0]].push_back(p[1]);
            adj[p[1]].push_back(p[0]);
        }
        int start = -1;
        for (auto& [k, v] : adj) {
            if (v.size() == 1) { start = k; break; }
        }
        int n = adj.size();
        vector<int> res;
        res.push_back(start);
        int prev = INT_MIN;
        int cur = start;
        while ((int)res.size() < n) {
            for (int nb : adj[cur]) {
                if (nb != prev) {
                    res.push_back(nb);
                    prev = cur;
                    cur = nb;
                    break;
                }
            }
        }
        return res;
    }
};
