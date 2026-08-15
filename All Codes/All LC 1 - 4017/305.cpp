// Link: https://leetcode.com/problems/number-of-islands-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * alpha(k))  SC: O(m*n)
// Approach: union-find; on each addLand, mark the cell water->land (islands++),
// then union with any of the 4 neighbors that are already land (islands--)
class Solution {
    vector<int> parent, rank_;

    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (rank_[ra] < rank_[rb]) swap(ra, rb);
        parent[rb] = ra;
        if (rank_[ra] == rank_[rb]) rank_[ra]++;
    }

public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        parent.resize(m * n);
        rank_.assign(m * n, 0);
        iota(parent.begin(), parent.end(), 0);

        int islands = 0;
        vector<int> res;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto& p : positions) {
            int r = p[0], c = p[1];
            if (grid[r][c] == 1) { res.push_back(islands); continue; }
            grid[r][c] = 1;
            islands++;
            int idx = r * n + c;
            for (auto& d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] != 1) continue;
                int nidx = nr * n + nc;
                if (find(idx) != find(nidx)) {
                    unite(idx, nidx);
                    islands--;
                }
            }
            res.push_back(islands);
        }
        return res;
    }
};
