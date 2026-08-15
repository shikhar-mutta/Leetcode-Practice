// Link: https://leetcode.com/problems/minimize-the-maximum-edge-weight-of-graph/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> revAdj(n); // B -> A with weight (reversed)
        int maxW = 0;
        for (auto& e : edges) {
            int a = e[0], b = e[1], w = e[2];
            revAdj[b].push_back({a, w});
            maxW = max(maxW, w);
        }

        auto reachableCount = [&](int X) -> int {
            vector<bool> vis(n, false);
            vis[0] = true;
            queue<int> q;
            q.push(0);
            int cnt = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto& [v, w] : revAdj[u]) {
                    if (w <= X && !vis[v]) {
                        vis[v] = true;
                        cnt++;
                        q.push(v);
                    }
                }
            }
            return cnt;
        };

        if (reachableCount(maxW) < n) return -1;

        int lo = 1, hi = maxW;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (reachableCount(mid) == n) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
