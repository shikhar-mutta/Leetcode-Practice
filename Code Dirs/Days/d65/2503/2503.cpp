// Link: https://leetcode.com/problems/maximum-number-of-points-from-grid-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C log(R*C) + Q log Q), SC: O(R*C + Q)
// Approach: process queries sorted ascending; expand a min-heap flood fill from (0,0), popping
// and counting cells whose value is strictly less than the current query, before recording the
// answer — reuses visited state and heap across queries since counts are monotonic.
class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int R = grid.size(), C = grid[0].size();
        int Q = queries.size();
        vector<int> order(Q);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        vector<vector<int>> visited(R, vector<int>(C, 0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;

        vector<int> ans(Q, 0);
        int count = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        for (int idx : order) {
            int q = queries[idx];
            while (!pq.empty() && get<0>(pq.top()) < q) {
                auto [val, r, c] = pq.top(); pq.pop();
                count++;
                for (int k = 0; k < 4; k++) {
                    int nr = r+dr[k], nc = c+dc[k];
                    if (nr<0||nr>=R||nc<0||nc>=C||visited[nr][nc]) continue;
                    visited[nr][nc] = 1;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
            ans[idx] = count;
        }
        return ans;
    }
};
