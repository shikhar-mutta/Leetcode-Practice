// Link: https://leetcode.com/problems/check-knight-tour-configuration/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false;
        int n = grid.size();
        vector<pair<int,int>> pos(n * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                pos[grid[i][j]] = {i, j};

        for (int k = 1; k < n * n; k++) {
            int dr = abs(pos[k].first - pos[k-1].first);
            int dc = abs(pos[k].second - pos[k-1].second);
            if (!((dr == 1 && dc == 2) || (dr == 2 && dc == 1))) return false;
        }
        return true;
    }
};
