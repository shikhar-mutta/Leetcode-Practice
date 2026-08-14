// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int rowCost = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m/2; j++)
                if (grid[i][j] != grid[i][m-1-j]) rowCost++;

        int colCost = 0;
        for (int j = 0; j < m; j++)
            for (int i = 0; i < n/2; i++)
                if (grid[i][j] != grid[n-1-i][j]) colCost++;

        return min(rowCost, colCost);
    }
};
