// Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotate90(vector<vector<int>>& m) {
        int n = m.size();
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[j][n-1-i] = m[i][j];
        return res;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int k = 0; k < 4; k++) {
            if (mat == target) return true;
            mat = rotate90(mat);
        }
        return false;
    }
};
