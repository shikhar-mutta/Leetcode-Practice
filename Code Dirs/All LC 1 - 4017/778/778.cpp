// Link: https://leetcode.com/problems/swim-in-rising-water/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 log n) SC: O(n^2)
// Approach: Dijkstra-style: from (0,0), always expand the neighbor with the smallest elevation via a min-heap; track the running max elevation encountered on the path, which is the answer once (n-1,n-1) is reached.
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int ans = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!pq.empty()) {
            auto [h, r, c] = pq.top(); pq.pop();
            ans = max(ans, h);
            if (r == n-1 && c == n-1) return ans;
            for (int d = 0; d < 4; d++) {
                int nr = r+dr[d], nc = c+dc[d];
                if (nr>=0&&nr<n&&nc>=0&&nc<n&&!visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({grid[nr][nc], nr, nc});
                }
            }
        }
        return ans;
    }
};
