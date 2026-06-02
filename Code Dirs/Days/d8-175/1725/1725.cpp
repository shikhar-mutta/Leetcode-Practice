// Link: https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countGoodRectangles(vector<vector<int>> &rectangles)
    {
        int maxLen = 0; // To keep track of the maximum square side length
        int count = 0;  // To count the number of rectangles that can form the largest square

        for (const auto &rect : rectangles)
        {
            int side = min(rect[0], rect[1]); // The largest square side that can be formed from the rectangle
            if (side > maxLen)
            {
                maxLen = side; // Update the maximum square side length
                count = 1;     // Reset count for the new maximum
            }
            else if (side == maxLen)
            {
                count++; // Increment count for rectangles that can form the largest square
            }
        }

        return count; // Return the total count of rectangles that can form the largest square
    }
};
