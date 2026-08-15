// Link: https://leetcode.com/problems/right-triangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(n+m)
// Approach: Precompute row and column sums of 1s. Each 1-cell can serve as
// the right-angle vertex of a right triangle by pairing with any other 1 in
// its row and any other 1 in its column, giving (row[i]-1)*(col[j]-1)
// triangles per cell; sum over all 1-cells.
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int row[1005]={};
        int col[1005]={};

        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res += (long long)((row[i] - 1) * (col[j] - 1));
                }
            }
        }

        return res;
    }
};
