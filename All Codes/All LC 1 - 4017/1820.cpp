// Link: https://leetcode.com/problems/maximum-number-of-accepted-invitations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid_;
    vector<int> matchCol;
    vector<bool> visited;

    bool tryKuhn(int r, int cols) {
        for (int c = 0; c < cols; c++) {
            if (grid_[r][c] == 1 && !visited[c]) {
                visited[c] = true;
                if (matchCol[c] == -1 || tryKuhn(matchCol[c], cols)) {
                    matchCol[c] = r;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumInvitations(vector<vector<int>>& grid) {
        grid_ = grid;
        int rows = grid.size(), cols = grid[0].size();
        matchCol.assign(cols, -1);

        int count = 0;
        for (int r = 0; r < rows; r++) {
            visited.assign(cols, false);
            if (tryKuhn(r, cols)) count++;
        }
        return count;
    }
};
