// Link: https://leetcode.com/problems/container-with-most-water/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of elements in the input array
    // SC: O(1)
    // Approach:
    //   1. We will use two pointers, one at the beginning and one at the end of the array.
    //   2. We will calculate the area formed by the two pointers and update the maximum area if the current area is greater than the maximum area.
    //   3. We will move the pointer pointing to the shorter line towards the other pointer, as moving the pointer pointing to the longer line will not increase the area.
    //   4. We will repeat steps 2 and 3 until the two pointers meet.
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int best = 0;
        while (l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            best = max(best, area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return best;
    }
};
