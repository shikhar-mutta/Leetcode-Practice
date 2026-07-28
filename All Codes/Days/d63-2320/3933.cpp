// Link: https://leetcode.com/problems/largest-local-values-in-a-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*x) worst case, with early exit on violation SC: O(1)
// Approach: for each non-zero cell (r,c) with value x, scan every cell
// within x rows and x columns (clipped to the matrix), skipping the 4
// corner cells at exact distance (x,x), and check none exceeds x —
// bailing out early on the first violation found.
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int count = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int x = matrix[r][c];
                if (x == 0) continue;
                bool isMax = true;
                for (int dr = -x; dr <= x && isMax; dr++) {
                    int nr = r + dr;
                    if (nr < 0 || nr >= n) continue;
                    for (int dc = -x; dc <= x; dc++) {
                        if (abs(dr) == x && abs(dc) == x) continue;
                        int nc = c + dc;
                        if (nc < 0 || nc >= m) continue;
                        if (matrix[nr][nc] > x) { isMax = false; break; }
                    }
                }
                if (isMax) count++;
            }
        }
        return count;
    }
};
