// Link: https://leetcode.com/problems/trapping-rain-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(const vector<int> &height)
    {
        int n = height.size();
        if (n < 3)
            return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int trapped = 0;

        while (left < right)
        {
            if (height[left] < height[right])
            {
                // process left side
                left_max = max(left_max, height[left]);
                trapped += left_max - height[left];
                ++left;
            }
            else
            {
                // process right side
                right_max = max(right_max, height[right]);
                trapped += right_max - height[right];
                --right;
            }
        }
        return trapped;
    }
};
