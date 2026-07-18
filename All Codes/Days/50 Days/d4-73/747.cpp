// Link: https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int index, i = 0;
        int mx1, mx2;
        for (auto val : nums)
        {
            // Update the maximum and second maximum values
            if (mx1 < val || !mx1)
            {
                mx2 = mx1;
                mx1 = val;
                index = i;
            }
            else if (mx2 < val)
            {
                mx2 = val;
            }
            i++;
        }
        if (mx2 * 2 <= mx1)
            return index;
        return -1;
    }
};
