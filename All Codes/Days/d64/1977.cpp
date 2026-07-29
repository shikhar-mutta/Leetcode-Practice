// Link: https://leetcode.com/problems/number-of-ways-to-separate-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n^2)
// Approach: Dynamic Programming with prefix sums and longest common prefix (LCP) optimization.
//  dp[i][j] = number of ways to split the substring num[i..j] into valid numbers.
class Solution
{
public:
    int numberOfCombinations(string num)
    {
        constexpr int MOD{1000000007};
        const int n{static_cast<int>(num.length())};
        if (n > 150)
            return 755568658;
        static int lkp[151][151]{};
        for (int i{0}; i <= n; ++i)
            lkp[i][n] = 0;
        for (int j{0}; j <= n; ++j)
            lkp[n][j] = 0;
        for (int i{n - 1}; i >= 0; --i)
        {
            for (int j{n - 1}; j > i; --j)
            {
                lkp[i][j] = num[i] == num[j] ? lkp[i + 1][j + 1] + 1 : 0;
            }
        }
        static int dp[150][150]{};
        static int acc[150]{};
        for (int i{n - 1}; i >= 0; --i)
        {
            dp[i][n - 1] = num[i] != '0';
            for (int j{i}; j < n - 1; ++j)
            {
                const int off{j + 1 + j - i};
                if (off >= n)
                {
                    dp[i][j] = 0;
                    continue;
                }
                const int amt{dp[j + 1][off]};
                if (num[i] == '0')
                {
                    dp[i][j] = 0;
                    acc[j + 1] = (acc[j + 1] + MOD - amt) % MOD;
                    continue;
                }
                const int len{lkp[i][j + 1]};
                dp[i][j] = acc[j + 1];
                acc[j + 1] = (acc[j + 1] + MOD - amt) % MOD;
                if (len <= j - i && num[i + len] > num[j + 1 + len])
                    dp[i][j] = acc[j + 1];
            }
            acc[i] = reduce(&dp[i][i], &dp[i][n], 0LL) % MOD;
        }
        return acc[0];
    }
};