// Link: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN;
        // find the two smallest and two largest numbers in the array
        for (int num : nums)
        {
            if (num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2)
                min2 = num;

            if (num > max1)
            {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2)
                max2 = num;
        }

        // calculate the product difference
        return max1 * max2 - min1 * min2;
    }
};
