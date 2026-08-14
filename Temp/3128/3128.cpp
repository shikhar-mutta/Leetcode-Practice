// Link: https://leetcode.com/problems/right-triangles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> rowCount(n, 0), colCount(m, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]) { rowCount[i]++; colCount[j]++; }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j]) ans += (long long)(rowCount[i] - 1) * (colCount[j] - 1);
        return ans;
    }
};
