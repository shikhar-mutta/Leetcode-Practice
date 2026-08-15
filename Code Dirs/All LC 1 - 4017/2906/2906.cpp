// Link: https://leetcode.com/problems/construct-product-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        const int MOD = 12345;
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> cells;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cells.push_back({i, j});

        vector<vector<int>> p(n, vector<int>(m, 0));
        long long prefix = 1;
        for (auto& [i, j] : cells) {
            p[i][j] = prefix;
            prefix = prefix * grid[i][j] % MOD;
        }
        long long suffix = 1;
        for (int idx = (int)cells.size() - 1; idx >= 0; idx--) {
            auto [i, j] = cells[idx];
            p[i][j] = (int)((long long)p[i][j] * suffix % MOD);
            suffix = suffix * grid[i][j] % MOD;
        }
        return p;
    }
};
