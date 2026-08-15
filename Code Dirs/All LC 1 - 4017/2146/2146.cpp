// Link: https://leetcode.com/problems/k-highest-ranked-items-within-a-price-range/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        int low = pricing[0], high = pricing[1];
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        visited[start[0]][start[1]] = true;
        vector<tuple<int,int,int,int>> items;
        int dist = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [r, c] = q.front(); q.pop();
                int price = grid[r][c];
                if (price >= 1 && price >= low && price <= high) {
                    items.push_back({dist, price, r, c});
                }
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                    if (visited[nr][nc] || grid[nr][nc] == 0) continue;
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
            dist++;
        }
        sort(items.begin(), items.end());
        vector<vector<int>> res;
        for (int i = 0; i < (int)items.size() && i < k; i++) {
            auto& [d, p, r, c] = items[i];
            res.push_back({r, c});
        }
        return res;
    }
};
