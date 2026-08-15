// Link: https://leetcode.com/problems/last-day-where-you-can-still-cross/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canCross(int row, int col, int day, vector<vector<int>>& cells) {
        vector<vector<bool>> water(row, vector<bool>(col, false));
        for (int i = 0; i < day; i++) {
            water[cells[i][0]-1][cells[i][1]-1] = true;
        }
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int,int>> q;
        for (int c = 0; c < col; c++) {
            if (!water[0][c]) { q.push({0, c}); visited[0][c] = true; }
        }
        int dr[4] = {0,0,1,-1};
        int dc[4] = {1,-1,0,0};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == row - 1) return true;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= row || nc < 0 || nc >= col) continue;
                if (visited[nr][nc] || water[nr][nc]) continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int lo = 1, hi = cells.size();
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (canCross(row, col, mid, cells)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
};
