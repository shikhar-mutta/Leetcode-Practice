// Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> order;
        queue<int> q; q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : children[u]) q.push(v);
        }

        vector<int> down(n, 1);
        int best = 1;
        for (int i = (int)order.size() - 1; i >= 0; i--) {
            int u = order[i];
            int top1 = 0, top2 = 0;
            for (int v : children[u]) {
                if (s[v] == s[u]) continue;
                int d = down[v];
                if (d > top1) { top2 = top1; top1 = d; }
                else if (d > top2) { top2 = d; }
            }
            down[u] = top1 + 1;
            best = max(best, top1 + top2 + 1);
        }
        return best;
    }
};
