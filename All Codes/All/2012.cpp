// Link: https://leetcode.com/problems/sum-of-beauty-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of elements in the array
// SC: O(n) where n is the number of elements in the array
// Approach:
// 1. We will create two arrays leftMax and rightMin to store the maximum value from the left and the minimum value from the right for each index.
// 2. We will iterate through the array and check for each index if the value is greater than the maximum value from the left and less than the minimum value from the right. If it is, we will add 2 to the beauty
// 3. If the value is greater than the previous value and less than the next value, we will add 1 to the beauty
// 4. Finally, we will return the beauty
class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n), rightMin(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        int beauty = 0;
        for (int i = 1; i <= n - 2; i++)
        {
            if (leftMax[i - 1] < nums[i] && nums[i] < rightMin[i + 1])
            {
                beauty += 2;
            }
            else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
            {
                beauty += 1;
            }
        }
        return beauty;
    }
};
