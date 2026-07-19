// Link: https://leetcode.com/problems/maximum-strength-of-a-group/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of elements in the array.
    // SC: O(1) as we are using constant space.
    // Approach:
    //  1. Count the number of negative numbers in the array.
    //  2. If the count of negative numbers is even, multiply all non-zero numbers and return the product.
    //  3. If the count of negative numbers is odd, sort the array and multiply all non-zero numbers except the largest negative number and return the product.
    //  4. If the product is zero, return zero.
    long long maxStrength(vector<int> &nums)
    {
        int c = 0, multiplied = 0;
        long long s = 1;
        if (nums.size() == 1)
            return nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                c++;
        }
        if (c % 2 == 0)
        {
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                    continue;
                s *= nums[i];
                multiplied = 1;
            }
        }
        else
        {
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size(); i++)
            {
                if (c == 1)
                {
                    c--;
                    continue;
                }
                if (nums[i] == 0)
                    continue;
                s *= nums[i];
                multiplied = 1;
                c--;
            }
        }
        if (multiplied)
            return s;
        return 0;
    }
};
