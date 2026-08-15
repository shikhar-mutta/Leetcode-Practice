// Link: https://leetcode.com/problems/count-good-integers-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(10 * 20 * 2)  SC: O(10 * 20 * 2)
// Approach: We can use digit dynamic programming to count the number of good integers in the range [l, r]. We can define a dp array where dp[pos][prev][started] represents the number of good integers that can be formed from the current position pos, with the previous digit being prev, and whether we have started forming the number or not. We can iterate through all the digits from 0 to 9 and check if the absolute difference between the current digit and the previous digit is less than or equal to k. If it is, we can continue forming the number.
class Solution
{
public:
    long long dp[20][11][2];
    string s;
    int K;

    long long dfs(int pos, int prev, bool started, bool tight)
    {
        if (pos == (int)s.size())
            return started ? 1 : 0;

        if (!tight && dp[pos][prev + 1][started] != -1)
            return dp[pos][prev + 1][started];

        int lim = tight ? s[pos] - '0' : 9;
        long long res = 0;

        for (int d = 0; d <= lim; d++)
        {
            bool ntight = tight && (d == lim);
            if (!started)
            {
                if (d == 0)
                    res += dfs(pos + 1, -1, false, ntight);
                else
                    res += dfs(pos + 1, d, true, ntight);
            }
            else
            {
                if (abs(d - prev) <= K)
                    res += dfs(pos + 1, d, true, ntight);
            }
        }

        if (!tight)
            dp[pos][prev + 1][started] = res;
        return res;
    }

    long long calc(long long x)
    {
        if (x <= 0)
            return 0;
        s = to_string(x);
        memset(dp, -1, sizeof(dp));
        return dfs(0, -1, false, true);
    }

    long long goodIntegers(long long l, long long r, int k)
    {
        K = k;
        return calc(r) - calc(l - 1);
    }
};
