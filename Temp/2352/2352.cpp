// Link: https://leetcode.com/problems/equal-row-and-column-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> rowCount;
        for (auto& row : grid) rowCount[row]++;
        int count = 0;
        for (int c = 0; c < n; c++) {
            vector<int> col(n);
            for (int r = 0; r < n; r++) col[r] = grid[r][c];
            if (rowCount.count(col)) count += rowCount[col];
        }
        return count;
    }
};
