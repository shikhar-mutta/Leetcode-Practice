// Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> rowOnes(m, 0), colOnes(n, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) { rowOnes[i]++; colOnes[j]++; }

        vector<vector<int>> diff(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                diff[i][j] = rowOnes[i] + colOnes[j] - (n - rowOnes[i]) - (m - colOnes[j]);
        return diff;
    }
};
