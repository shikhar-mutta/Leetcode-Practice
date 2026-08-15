// Link: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<long long>> maxDp(rows, vector<long long>(cols)), minDp(rows, vector<long long>(cols));

        maxDp[0][0] = minDp[0][0] = grid[0][0];
        for (int j = 1; j < cols; j++) maxDp[0][j] = minDp[0][j] = maxDp[0][j-1] * grid[0][j];
        for (int i = 1; i < rows; i++) maxDp[i][0] = minDp[i][0] = maxDp[i-1][0] * grid[i][0];

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                long long a = maxDp[i-1][j] * grid[i][j];
                long long b = minDp[i-1][j] * grid[i][j];
                long long c = maxDp[i][j-1] * grid[i][j];
                long long d = minDp[i][j-1] * grid[i][j];
                maxDp[i][j] = max({a, b, c, d});
                minDp[i][j] = min({a, b, c, d});
            }
        }

        long long result = maxDp[rows-1][cols-1];
        if (result < 0) return -1;
        return (int)(result % MOD);
    }
};
