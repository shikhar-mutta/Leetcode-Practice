// Link: https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach:
//  1. We can use a brute force approach to solve this problem. We can iterate through all the integers from 1 to n-1 and check if both the integer and its complement (n - integer) do not contain the digit 0. If we find such a pair, we can return it as the result. If we do not find any such pair, we can return an empty vector.
//  2. We can use a helper function to check if a given integer contains the digit 0 or not. We can use a while loop to iterate through the digits of the integer and check if any of the digits is 0. If we find a 0, we can return false. If we do not find any 0, we can return true.
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        for (int a = 1; a < n; ++a)
        {
            if (noZero(a) && noZero(n - a))
                return {a, n - a};
        }
        return {};
    }

private:
    bool noZero(int x)
    {
        while (x)
        {
            if (x % 10 == 0)
                return false;
            x /= 10;
        }
        return true;
    }
};