// Link: https://leetcode.com/problems/n-queens-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n!)  SC: O(n) recursion depth
// Approach: backtracking with column + two diagonal boolean arrays, count leaf placements
class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false), diag1(2*n, false), diag2(2*n, false);
        int count = 0;
        function<void(int)> bt = [&](int row) {
            if (row == n) { count++; return; }
            for (int c = 0; c < n; c++) {
                if (cols[c] || diag1[row+c] || diag2[row-c+n]) continue;
                cols[c] = diag1[row+c] = diag2[row-c+n] = true;
                bt(row + 1);
                cols[c] = diag1[row+c] = diag2[row-c+n] = false;
            }
        };
        bt(0);
        return count;
    }
};
