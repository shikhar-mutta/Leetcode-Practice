// Link: https://leetcode.com/problems/count-no-zero-pairs-that-sum-to-n/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10^2 * 2^3 * len(n)) where len(n) is the number of digits in n.
// SC: O(len(n) * 2^3) where len(n) is the number of digits in n.
// Approach:
// 1. We can use dynamic programming to solve this problem.
// 2. We can use a 4D array to store the number of ways to form pairs of numbers that sum to n without any zeros in their digits.
// 3. We can use a recursive function to calculate the number of ways to form pairs of numbers that sum to n without any zeros in their digits.
// 4. We can use memoization to store the results of the recursive function to avoid recalculating the same subproblems.
// 5. We can iterate through the digits of n and for each digit, we can iterate through all possible pairs of digits that sum to the current digit
// 6. We can check if the current pair of digits is valid (i.e., does not contain any zeros) and if it is, we can recursively call the function for the next digit.
class Solution
{
    long long memo[20][2][2][2];
    string s_rev;

    long long dfs(int idx, int carry, int a_active, int b_active)
    {
        if (idx == s_rev.length() + 1)
        {
            return (carry == 0 && a_active == 0 && b_active == 0) ? 1 : 0;
        }

        if (memo[idx][carry][a_active][b_active] != -1)
        {
            return memo[idx][carry][a_active][b_active];
        }

        long long ways = 0;
        int target = (idx < s_rev.length()) ? (s_rev[idx] - '0') : 0;

        for (int d_a = 0; d_a <= 9; ++d_a)
        {
            if (idx == 0 && d_a == 0)
                continue;
            if (!a_active && d_a > 0)
                continue;

            for (int d_b = 0; d_b <= 9; ++d_b)
            {
                if (idx == 0 && d_b == 0)
                    continue;
                if (!b_active && d_b > 0)
                    continue;

                int sum = d_a + d_b + carry;
                if (sum % 10 == target)
                {
                    int next_a = (d_a > 0) ? 1 : 0;
                    int next_b = (d_b > 0) ? 1 : 0;

                    ways += dfs(idx + 1, sum / 10, next_a, next_b);
                }
            }
        }

        return memo[idx][carry][a_active][b_active] = ways;
    }

public:
    long long countNoZeroPairs(long long n)
    {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        s_rev = s;

        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 1, 1);
    }
};
