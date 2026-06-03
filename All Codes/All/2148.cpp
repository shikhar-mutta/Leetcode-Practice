// Link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach: Use Min & Max then count comes between them. TC: O(n) SC: O(1)
    int countElements(vector<int> &nums)
    {
        int count = 0;
        // Find the minimum and maximum values in the array
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        for (int num : nums)
        {
            // Strictly smaller than maxVal and strictly greater than minVal
            if (num > minVal && num < maxVal)
            {
                count++;
            }
        }

        return count;
    }
};
