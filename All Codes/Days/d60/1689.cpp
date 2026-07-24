// Link: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input string.
// SC: O(1) for storing the maximum digit.
// Approach:
//     1. Iterate through the string n and find the maximum digit.
//     2. The minimum number of deci-binary numbers needed to sum up to n is equal to the maximum digit in n.
//     3. Return the maximum digit as the result.
class Solution
{
public:
    int minPartitions(string n)
    {
        char mx = '0';
        for (char c : n)
            mx = max(mx, c);
        return mx - '0';
    }
};