// Link: https://leetcode.com/problems/third-maximum-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // optional is used when we want to represent the presence or absence of a value.
        optional<int> first, second, third;
        for (int n : nums)
        {
            // Skip duplicates.
            if (n == first || n == second || n == third)
                continue;

            // Update the three maximums.
            if (!first || n > *first)
            {
                third = second;
                second = first;
                first = n;
            }
            else if (!second || n > *second)
            {
                third = second;
                second = n;
            }
            else if (!third || n > *third)
            {
                third = n;
            }
        }
        // If the third maximum does not exist, return the maximum number.
        return third ? *third : *first;
    }
};