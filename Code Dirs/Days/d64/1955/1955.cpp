// Link: https://leetcode.com/problems/count-number-of-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: dp0/dp1/dp2 = number of subsequences ending in a run of 0s / 0s
// then 1s / 0s then 1s then 2s (each count >=1) seen so far. On seeing digit
// d, dpD = dpD*2 + (dpD_prev_stage or 1 for d=0), since each existing valid
// subsequence can include or skip this occurrence, plus new ones starting here.
class Solution
{
public:
    int countSpecialSubsequences(vector<int> &nums)
    {
        const long long MOD = 1e9 + 7;
        long long dp0 = 0, dp1 = 0, dp2 = 0;
        for (int x : nums)
        {
            if (x == 0)
                dp0 = (dp0 * 2 + 1) % MOD;
            else if (x == 1)
                dp1 = (dp1 * 2 + dp0) % MOD;
            else
                dp2 = (dp2 * 2 + dp1) % MOD;
        }
        return (int)dp2;
    }
};
