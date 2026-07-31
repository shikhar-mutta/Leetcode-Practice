// Link: https://leetcode.com/problems/number-of-beautiful-integers-in-the-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(len * len * k), SC: O(len * len * k)
// Approach: answer = f(high) - f(low-1), f(X) via digit DP tracking (even-digit-count minus
// odd-digit-count, offset to stay non-negative) and running remainder mod k, memoized on
// (position, diff, mod) for the non-tight/started branch.
class Solution
{
public:
    int K;
    string num;
    int len;
    vector<vector<vector<int>>> memo; // memo[pos][diff+len][mod], -1 = uncomputed

    long long dp(int pos, int diff, int mod, bool tight, bool started)
    {
        if (pos == len)
            return (started && diff == 0 && mod == 0) ? 1 : 0;
        if (!tight && started && memo[pos][diff + len][mod] != -1)
            return memo[pos][diff + len][mod];

        int limit = tight ? (num[pos] - '0') : 9;
        long long total = 0;
        for (int d = 0; d <= limit; d++)
        {
            bool nstarted = started || d > 0;
            if (!nstarted)
            {
                total += dp(pos + 1, diff, mod, tight && d == limit, false);
                continue;
            }
            int ndiff = diff + (d % 2 == 0 ? 1 : -1);
            int nmod = (mod * 10 + d) % K;
            total += dp(pos + 1, ndiff, nmod, tight && d == limit, true);
        }
        if (!tight && started)
            memo[pos][diff + len][mod] = (int)total;
        return total;
    }

    long long f(long long X)
    {
        if (X < 0)
            return 0;
        num = to_string(X);
        len = num.size();
        memo.assign(len, vector<vector<int>>(2 * len + 1, vector<int>(K, -1)));
        return dp(0, 0, 0, true, false);
    }

    int numberOfBeautifulIntegers(int low, int high, int k)
    {
        K = k;
        return (int)(f(high) - f((long long)low - 1));
    }
};
