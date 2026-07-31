// Link: https://leetcode.com/problems/equal-sum-grid-partition-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rowSum(m, 0), colSum(n, 0);
        long long total = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                rowSum[i] += grid[i][j];
                colSum[j] += grid[i][j];
                total += grid[i][j];
            }

        long long acc = 0;
        for (int i = 0; i < m - 1; i++) {
            acc += rowSum[i];
            if (2 * acc == total) return true;
        }
        acc = 0;
        for (int j = 0; j < n - 1; j++) {
            acc += colSum[j];
            if (2 * acc == total) return true;
        }
        return false;
    }
};
