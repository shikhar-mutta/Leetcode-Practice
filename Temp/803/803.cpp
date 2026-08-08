// Link: https://leetcode.com/problems/bricks-falling-when-hit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((m*n + k) α(m*n)) SC: O(m*n)
// Approach: remove all hit bricks first, then union-find the remaining stable structure (with a virtual "roof" node connected to all row-0 bricks). Process hits in reverse, adding each brick back and unioning with its neighbors/roof; the number of bricks that "fall" for that hit equals the growth in the roof component's size minus 1 (the added brick itself), clamped at 0.
class DSU {
    vector<int> parent, rnk, sz;
public:
    DSU(int n) { parent.resize(n); iota(parent.begin(), parent.end(), 0); rnk.assign(n,0); sz.assign(n,1); }
    int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); }
    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (rnk[rx] < rnk[ry]) swap(rx, ry);
        parent[ry] = rx;
        sz[rx] += sz[ry];
        if (rnk[rx] == rnk[ry]) rnk[rx]++;
    }
    int size(int x) { return sz[find(x)]; }
};

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> g = grid;
        for (auto& h : hits) g[h[0]][h[1]] = 0;

        DSU dsu(m*n + 1);
        int roof = m*n;
        auto idx = [&](int r, int c) { return r*n + c; };
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (g[r][c] != 1) continue;
                if (r == 0) dsu.unite(idx(r,c), roof);
                if (r > 0 && g[r-1][c] == 1) dsu.unite(idx(r,c), idx(r-1,c));
                if (c > 0 && g[r][c-1] == 1) dsu.unite(idx(r,c), idx(r,c-1));
            }
        }

        int k = hits.size();
        vector<int> res(k, 0);
        for (int i = k-1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) continue;
            int before = dsu.size(roof);
            g[r][c] = 1;
            if (r == 0) dsu.unite(idx(r,c), roof);
            for (int d = 0; d < 4; d++) {
                int nr = r+dr[d], nc = c+dc[d];
                if (nr>=0 && nr<m && nc>=0 && nc<n && g[nr][nc]==1) dsu.unite(idx(r,c), idx(nr,nc));
            }
            int after = dsu.size(roof);
            res[i] = max(0, after - before - 1);
        }
        return res;
    }
};
