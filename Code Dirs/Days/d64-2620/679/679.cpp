// Link: https://leetcode.com/problems/24-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)  (fixed 4 numbers, bounded branching)  SC: O(1)
//  Approach: brute-force recursion. Pick any pair from the current list,
//  combine with +,-,*,/ (both subtraction/division orders), replace the
//  pair with the result, and recurse until one number remains, checking
//  if it's ~24.
class Solution
{
public:
    bool judgePoint24(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        do
        {
            if (valid(nums))
                return true;
        } while (next_permutation(nums.begin(), nums.end()));
        return false;
    }

private:
    bool valid(vector<int> &nums)
    {
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if (valid(a + b, c, d) || valid(a - b, c, d) || valid(a * b, c, d) ||
            valid(a / b, c, d))
            return true;
        if (valid(a, b + c, d) || valid(a, b - c, d) || valid(a, b * c, d) ||
            valid(a, b / c, d))
            return true;
        if (valid(a, b, c + d) || valid(a, b, c - d) || valid(a, b, c * d) ||
            valid(a, b, c / d))
            return true;
        return false;
    }
    bool valid(double a, double b, double c)
    {
        if (valid(a + b, c) || valid(a - b, c) || valid(a * b, c) ||
            b && valid(a / b, c))
            return true;
        if (valid(a, b + c) || valid(a, b - c) || valid(a, b * c) ||
            c && valid(a, b / c))
            return true;
        return false;
    }
    bool valid(double a, double b)
    {
        if (abs(a + b - 24.0) < 0.0001 || abs(a - b - 24.0) < 0.0001 ||
            abs(a * b - 24.0) < 0.0001 || b && abs(a / b - 24.0) < 0.0001)
            return true;
        return false;
    }
};