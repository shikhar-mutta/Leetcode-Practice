// Link: https://leetcode.com/problems/maximum-sum-of-an-hourglass/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int best = 0;
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                int sum = grid[i][j] + grid[i][j+1] + grid[i][j+2]
                        + grid[i+1][j+1]
                        + grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
                best = max(best, sum);
            }
        }
        return best;
    }
};
