// Link: https://leetcode.com/problems/minimum-score-by-changing-two-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of elements in the array.
    // SC: O(1) as we are using constant space.
    //  Approach:
    //   1. Find the three largest and three smallest elements in the array.
    //   2. Calculate the three possible scores by changing two elements to the same value
    //   3. Return the minimum score among the three possible scores.
    int minimizeSum(vector<int> &nums)
    {
        int n = nums.size();
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (num > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3)
                max3 = num;
            if (num < min1)
            {
                min3 = min2;
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
            {
                min3 = min2;
                min2 = num;
            }
            else if (num < min3)
                min3 = num;
        }
        int c1 = max1 - min3;
        int c2 = max2 - min2;
        int c3 = max3 - min1;
        return min(c1, min(c2, c3));
    }
};
