// Link: https://leetcode.com/problems/ways-to-make-a-fair-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array.
    // SC: O(1) for storing the result.
    // Approach:
    //       1. Calculate the total sum of even and odd indexed elements in the array.
    //       2. Iterate through the array and for each element, calculate the new sum of even and odd indexed elements after removing the current element.
    //       3. If the new sum of even indexed elements is equal to the new sum of odd indexed elements, increment the result counter.
    //       4. Return the result counter.
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        long long sufEven = 0, sufOdd = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
                sufEven += nums[i];
            else
                sufOdd += nums[i];
        }

        long long preEven = 0, preOdd = 0;
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
                sufEven -= nums[i];
            else
                sufOdd -= nums[i];

            if (preEven + sufOdd == preOdd + sufEven)
                ++res;

            if (i % 2 == 0)
                preEven += nums[i];
            else
                preOdd += nums[i];
        }
        return res;
    }
};
