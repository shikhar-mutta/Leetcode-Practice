// Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n)
// Approach: DP row by row, but instead of checking all n-1 other
// columns per cell (O(n) each), track just the smallest and
// second-smallest values of the previous row plus which column held the
// smallest. Each cell then picks: prevSecondMin if it was in the same
// column as prevMin, else prevMin — both O(1).
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> prev = grid[0];
        for (int r = 1; r < n; r++) {
            int min1 = INT_MAX, min1Idx = -1, min2 = INT_MAX;
            for (int c = 0; c < n; c++) {
                if (prev[c] < min1) { min2 = min1; min1 = prev[c]; min1Idx = c; }
                else if (prev[c] < min2) { min2 = prev[c]; }
            }
            vector<int> cur(n);
            for (int c = 0; c < n; c++) {
                cur[c] = grid[r][c] + (c == min1Idx ? min2 : min1);
            }
            prev = cur;
        }
        return *min_element(prev.begin(), prev.end());
    }
};
