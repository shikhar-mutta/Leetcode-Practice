// Link: https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        vector<vector<int>> cur = mat;

        // lambda function to rotate the matrix 90 degrees clockwise
        // & is used to capture the cur matrix by reference, so that we can modify it in place here n
        auto rotate90 = [&](vector<vector<int>> &m)
        {
            vector<vector<int>> tmp(n, vector<int>(n));
            //  Rotate 90 degrees clockwise: tmp[j][n - 1 - i] = m[i][j]
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    tmp[j][n - 1 - i] = m[i][j];
            m = tmp;
        };

        // Try all 4 rotations (0, 90, 180, 270 degrees)
        for (int r = 0; r < 4; r++)
        {
            // direct compare 2D matrix, if they are the same, return true
            if (cur == target)
                return true;
            rotate90(cur);
        }
        return false;
    }
};
