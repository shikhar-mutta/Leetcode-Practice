// Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(r*c), SC: O(1) extra (grid reused in-place as a 2D prefix-sum table)
// Approach: Build the prefix-sum in place. Since sums only grow moving
// right/down, once a row/column position exceeds k, every cell further in
// that direction also exceeds k, so each row/column scan can break early
// (brCol tracks the furthest column reached so far to bound later rows).
class Solution {
public:
    static int countSubmatrices(vector<vector<int>>& grid, int k) {
        const int r = grid.size(), c = grid[0].size();
        int cnt = 0, brCol = c;
        if (grid[0][0] > k)
            return 0; // early stop
        cnt++;
        for (int j = 1; j < c; j++) {
            int& x = grid[0][j];
            x += grid[0][j - 1];
            if (x > k) // no need for computing for the rest cols
            {
                brCol = j;
                break;
            }
            cnt++;
        }
        for (int i = 1; i < r; i++) {
            grid[i][0] += grid[i - 1][0];
            if (grid[i][0] > k)
                break;
            cnt++;
            for (int j = 1; j < brCol; j++) {
                int& x = grid[i][j];
                x += grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
                if (x > k) {
                    brCol = j;
                    break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
