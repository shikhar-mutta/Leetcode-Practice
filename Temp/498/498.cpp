// Link: https://leetcode.com/problems/diagonal-traverse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(1) extra
// Approach: walk diagonally, bouncing off edges; direction alternates
// between up-right and down-left each diagonal
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        int r = 0, c = 0;
        bool goingUp = true;

        for (int i = 0; i < m * n; i++) {
            res.push_back(mat[r][c]);
            if (goingUp) {
                if (c == n - 1) { r++; goingUp = false; }
                else if (r == 0) { c++; goingUp = false; }
                else { r--; c++; }
            } else {
                if (r == m - 1) { c++; goingUp = true; }
                else if (c == 0) { r++; goingUp = true; }
                else { r++; c--; }
            }
        }
        return res;
    }
};
