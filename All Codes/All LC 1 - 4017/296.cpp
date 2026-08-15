// Link: https://leetcode.com/problems/best-meeting-point/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m+n)
// Approach: rows and columns are independent for Manhattan distance; optimal
// meeting point is the median row and median column of all 1s
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> rows, cols;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) { rows.push_back(i); cols.push_back(j); }

        sort(cols.begin(), cols.end());
        int medRow = rows[rows.size() / 2];
        int medCol = cols[cols.size() / 2];

        int dist = 0;
        for (int r : rows) dist += abs(r - medRow);
        for (int c : cols) dist += abs(c - medCol);
        return dist;
    }
};
