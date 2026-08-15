// Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit = 6000 + a + b;
        vector<vector<bool>> visited(limit + 1, vector<bool>(2, false));
        unordered_set<int> forb(forbidden.begin(), forbidden.end());
        queue<tuple<int,int,int>> q; // pos, steps, canBack(0/1)
        q.push({0, 0, 1});
        visited[0][1] = true;
        while (!q.empty()) {
            auto [pos, steps, canBack] = q.front(); q.pop();
            if (pos == x) return steps;
            int fwd = pos + a;
            if (fwd <= limit && !forb.count(fwd) && !visited[fwd][1]) {
                visited[fwd][1] = true;
                q.push({fwd, steps + 1, 1});
            }
            if (canBack) {
                int bwd = pos - b;
                if (bwd >= 0 && !forb.count(bwd) && !visited[bwd][0]) {
                    visited[bwd][0] = true;
                    q.push({bwd, steps + 1, 0});
                }
            }
        }
        return -1;
    }
};
