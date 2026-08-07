// Link: https://leetcode.com/problems/spiral-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(1) extra (excluding output)
// Approach: 4-boundary spiral fill top/right/bottom/left shrinking each pass, with guards before the last two sides
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, val = 1;
        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; c++) res[top][c] = val++;
            top++;
            for (int r = top; r <= bottom; r++) res[r][right] = val++;
            right--;
            if (top <= bottom) {
                for (int c = right; c >= left; c--) res[bottom][c] = val++;
                bottom--;
            }
            if (left <= right) {
                for (int r = bottom; r >= top; r--) res[r][left] = val++;
                left++;
            }
        }
        return res;
    }
};
