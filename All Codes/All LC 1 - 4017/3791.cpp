// Link: https://leetcode.com/problems/number-of-balanced-integers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^2 * 2^3 * len(n)) where len(n) is the number of digits in n.
// SC: O(len(n) * 2^3) where len(n) is the number of digits in n.
//  Approach:
//  1. We can use dynamic programming to solve this problem.
//  2. We can use a 4D array to store the number of ways to form pairs of numbers that sum to n without any zeros in their digits.
//  3. We can use a recursive function to calculate the number of ways to form pairs of numbers that sum to n without any zeros in their digits.
//  4. We can use memoization to store the results of the recursive function to avoid recalculating the same subproblems.
//  5. We can iterate through the digits of n and for each digit, we can iterate through all possible pairs of digits that sum to the current digit
//  6. We can check if the current pair of digits is valid (i.e., does not contain any zeros) and if it is, we can recursively call the function for the next digit.
class Solution
{
    long long countExact(const string &bound)
    {
        int len = bound.size();
        int OFFSET = 9 * len + 5;
        vector<vector<long long>> memo(len,
                                       vector<long long>(2 * OFFSET + 1, -1));
        function<long long(int, int, bool)> dfs = [&](int pos, int diff,
                                                      bool tight) -> long long
        {
            if (pos == len)
                return diff == 0 ? 1 : 0;
            if (!tight && memo[pos][diff + OFFSET] != -1)
                return memo[pos][diff + OFFSET];
            int lo = (pos == 0) ? 1 : 0;
            int hi = tight ? (bound[pos] - '0') : 9;
            long long res = 0;
            for (int d = lo; d <= hi; d++)
            {
                int delta = (pos % 2 == 0) ? d : -d;
                res += dfs(pos + 1, diff + delta, tight && d == hi);
            }
            if (!tight)
                memo[pos][diff + OFFSET] = res;
            return res;
        };
        return dfs(0, 0, true);
    }

    long long countUpTo(long long n)
    {
        if (n < 10)
            return 0;
        string digits = to_string(n);
        int L = digits.size();
        long long result = 0;
        for (int len = 2; len < L; len++)
            result += countExact(string(len, '9'));
        result += countExact(digits);
        return result;
    }

public:
    long long countBalanced(long long low, long long high)
    {
        return countUpTo(high) - countUpTo(low - 1);
    }
};
