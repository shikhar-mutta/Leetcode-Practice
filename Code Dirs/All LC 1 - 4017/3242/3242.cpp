// Link: https://leetcode.com/problems/design-neighbor-sum-service/description/

#include <bits/stdc++.h>
using namespace std;

class NeighborSum {
public:
    vector<vector<int>> grid;
    unordered_map<int,pair<int,int>> pos;
    int n;

    NeighborSum(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pos[grid[i][j]] = {i, j};
    }

    int adjacentSum(int value) {
        auto [i, j] = pos[value];
        int sum = 0;
        int di[4] = {-1, 1, 0, 0};
        int dj[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) sum += grid[ni][nj];
        }
        return sum;
    }

    int diagonalSum(int value) {
        auto [i, j] = pos[value];
        int sum = 0;
        int di[4] = {-1, -1, 1, 1};
        int dj[4] = {-1, 1, -1, 1};
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni >= 0 && ni < n && nj >= 0 && nj < n) sum += grid[ni][nj];
        }
        return sum;
    }
};
