// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m+n)  SC: O(1)
// Approach: start at top-right corner; move left if too big, down if too small
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c = matrix[0].size() - 1;
        while (r < (int)matrix.size() && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) c--;
            else r++;
        }
        return false;
    }
};
