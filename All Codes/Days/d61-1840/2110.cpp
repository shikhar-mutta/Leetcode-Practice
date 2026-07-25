// Link: https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the prices array.
// SC: O(1)
// Approach:
//  1. We use a two-pointer approach to find the length of each smooth descent period in the prices array. We initialize two pointers, left and right, to the start of the array. We iterate through the array using the right pointer and check if the current price is less than or equal to the previous price and if the difference between the current price and the previous price is 1. If both conditions are satisfied, we continue to the next price. If not, we calculate the length of the smooth descent period and add it to the result. We then move the left pointer to the current position of the right pointer and continue the process until we reach the end of the array.
//  2. Finally, we return the total number of smooth descent periods found in the prices array.
class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        int left = 0;
        int right = 0;
        long long ret = 0;
        while (right < prices.size())
        {
            if (right != 0 && (prices[right] > prices[right - 1] ||
                               prices[right - 1] - prices[right] != 1))
            {
                int n = (right - 1) - left + 1;
                ret += ((long long)n * (n + 1)) / 2;
                left = right;
            }
            right++;
        }
        int n = (right - 1) - left + 1;
        ret += ((long long)n * (n + 1)) / 2;
        return ret;
    }
};