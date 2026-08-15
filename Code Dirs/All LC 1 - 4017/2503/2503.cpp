// Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int qn = queries.size();
        vector<int> order(qn);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;

        vector<int> ans(qn, 0);
        int count = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        for (int idx : order) {
            int q = queries[idx];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                auto [val, r, c] = pq.top(); pq.pop();
                count++;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        pq.push({grid[nr][nc], nr, nc});
                    }
                }
            }
            ans[idx] = count;
        }
        return ans;
    }
};
