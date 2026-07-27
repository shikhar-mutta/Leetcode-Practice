// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows * cols) SC: O(rows * cols)
// Approach: flood fill each 4-connected island of nonzero cells, sum its
// values, and count islands whose sum is divisible by k.
class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        int dr[] = {0,0,1,-1}, dc[] = {1,-1,0,0};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0 || visited[r][c]) continue;
                long long sum = 0;
                queue<pair<int,int>> q;
                q.push({r, c});
                visited[r][c] = true;
                while (!q.empty()) {
                    auto [cr, cc] = q.front(); q.pop();
                    sum += grid[cr][cc];
                    for (int d = 0; d < 4; d++) {
                        int nr = cr + dr[d], nc = cc + dc[d];
                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                        if (grid[nr][nc] == 0 || visited[nr][nc]) continue;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
                if (sum % k == 0) count++;
            }
        }
        return count;
    }
};
