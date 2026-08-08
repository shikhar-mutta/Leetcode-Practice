// Link: https://leetcode.com/problems/find-all-groups-of-farmland/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int rows = land.size(), cols = land[0].size();
        vector<vector<int>> res;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (land[r][c] == 0) continue;
                if (r > 0 && land[r-1][c] == 1) continue;
                if (c > 0 && land[r][c-1] == 1) continue;
                int r2 = r, c2 = c;
                while (r2 + 1 < rows && land[r2+1][c] == 1) r2++;
                while (c2 + 1 < cols && land[r][c2+1] == 1) c2++;
                res.push_back({r, c, r2, c2});
            }
        }
        return res;
    }
};
