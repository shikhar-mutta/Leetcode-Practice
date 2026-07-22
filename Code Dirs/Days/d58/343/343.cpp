// Link: https://leetcode.com/problems/integer-break/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the input integer. We have two nested loops, the outer loop runs from 2 to n and the inner loop runs from 1 to i.
    // SC: O(n) where n is the input integer. We use a dp vector of size n+1 to store the maximum product for each integer from 1 to n.
    // Approach:
    //  1. We can use dynamic programming to solve this problem. We create a dp vector of size n+1, where dp[i] represents the maximum product we can get by breaking the integer i into at least two positive integers.
    //  2. We initialize dp[1] to 1, as the maximum product for integer 1 is 1. Then, we iterate through all integers from 2 to n. For each integer i, we iterate through all possible break points j from 1 to i-1. For each break point j, we calculate the maximum product by considering three cases:
    //     a. Not breaking the integer i at all, which gives us the product j * (i - j).
    //     b. Breaking the integer i into two parts, which gives us the product j * dp[i - j].
    //     c. Not breaking the integer i at all, which gives us the product dp[i].
    //  3. We take the maximum of these three cases and update dp[i] accordingly. Finally, we return dp[n] as the result.
    int integerBreak(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
        }
        return dp[n];
    }
};
