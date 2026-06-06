// Link: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int maxArea = 0, maxSqLen = 0;
        for (auto &d : dimensions)
        {
            int sqLen = d[0] * d[0] + d[1] * d[1];
            // Update max area & maxSqLen
            if (sqLen > maxSqLen)
            {
                maxSqLen = sqLen;
                maxArea = d[0] * d[1];
            }
            else if (sqLen == maxSqLen)
                maxArea = max(maxArea, d[0] * d[1]);
        };
        return maxArea;
    };
};