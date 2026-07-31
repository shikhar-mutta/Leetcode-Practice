// Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || visited[i][j]) continue;
                long long sum = 0;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [r,c] = q.front(); q.pop();
                    sum += grid[r][c];
                    for (int d = 0; d < 4; d++) {
                        int nr = r+dr[d], nc = c+dc[d];
                        if (nr<0||nr>=m||nc<0||nc>=n) continue;
                        if (grid[nr][nc]==0 || visited[nr][nc]) continue;
                        visited[nr][nc] = true;
                        q.push({nr,nc});
                    }
                }
                if (sum % k == 0) count++;
            }
        }

        return count;
    }
};
