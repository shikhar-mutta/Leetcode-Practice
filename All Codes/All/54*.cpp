// Link: https://leetcode.com/problems/spiral-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int top, bottom, left, right, r, c;
        top = 0;
        bottom = matrix.size() - 1;
        left = 0;
        right = matrix[0].size() - 1;
        while (bottom >= top && right >= left)
        {
            // left to right
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            // top to bottom
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // right to left
            // check if top and bottom are still valid
            if (bottom >= top)
            {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }   

            // bottom to top
            // check if left and right are still valid
            if(right >= left)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }
        return result;
    }
};