// Link: https://leetcode.com/problems/valid-arrangement-of-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> outdeg, indeg;
        for (auto& p : pairs) {
            adj[p[0]].push_back(p[1]);
            outdeg[p[0]]++;
            indeg[p[1]]++;
        }
        int start = pairs[0][0];
        for (auto& [node, od] : outdeg) {
            if (od - indeg[node] == 1) { start = node; break; }
        }
        unordered_map<int, int> ptr;
        vector<int> stk = {start};
        vector<int> path;
        while (!stk.empty()) {
            int node = stk.back();
            int& p = ptr[node];
            if (p < (int)adj[node].size()) {
                int next = adj[node][p];
                p++;
                stk.push_back(next);
            } else {
                path.push_back(node);
                stk.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> res;
        for (int i = 0; i + 1 < (int)path.size(); i++) res.push_back({path[i], path[i + 1]});
        return res;
    }
};
