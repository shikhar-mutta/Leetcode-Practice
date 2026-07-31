// Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(1)
// Approach: Making every row a palindrome and making every column a
// palindrome are independent alternatives (only one needs to hold). Count
// mismatched mirrored-pair flips required for each choice separately and
// return the cheaper one.
class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        int rowCost = 0;
        for (int i = 0; i < m; i++)
            for (int l = 0, r = n - 1; l < r; l++, r--)
                if (grid[i][l] != grid[i][r])
                    rowCost++;

        int colCost = 0;
        for (int j = 0; j < n; j++)
            for (int t = 0, b = m - 1; t < b; t++, b--)
                if (grid[t][j] != grid[b][j])
                    colCost++;

        return min(rowCost, colCost);
    }
};
