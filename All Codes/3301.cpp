// Link: https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of maximumHeight.
    // SC: O(1) where n is the number of maximumHeight.
    // Approach:
    //  1. Sort the maximumHeight in descending order.
    //  2. Iterate through the maximumHeight and check if the current height is equal to the next height. If it is, then decrement the next height by 1.
    //  3. If the current height is less than the next height, then decrement the next height by the difference between the current height and the next height plus 1.
    //  4. If the last height is less than or equal to 0, then return -1.
    //  5. Return the sum of the maximumHeight.
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        for (int i = 0; i < n - 1; i++)
        {
            if (maximumHeight[i] == maximumHeight[i + 1])
            {
                maximumHeight[i + 1] = maximumHeight[i + 1] - 1;
            }
            if (maximumHeight[i] < maximumHeight[i + 1])
            {
                maximumHeight[i + 1] = maximumHeight[i + 1] - ((maximumHeight[i + 1] - maximumHeight[i]) + 1);
            }
        }
        if (maximumHeight[n - 1] <= 0)
        {
            return -1;
        }
        long long sum = 0;
        for (long long val : maximumHeight)
        {
            sum += val;
        }
        return sum;
    }
};
