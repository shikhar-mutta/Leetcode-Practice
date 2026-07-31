// Link: https://leetcode.com/problems/maximize-score-after-n-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 * 2^n)  SC: O(n^2 + 2^n)
//  Approach: dp[mask] = max score for the subset of nums represented by mask.
//  For each mask, we can find the number of pairs already chosen by counting the
//  number of bits set in mask. Then we can iterate over all pairs of indices
//  that are set in mask, and calculate the score for that pair, and update dp[mask] accordingly. The final answer will be dp[(1 << n) - 1],
//  where n is the length of nums.
class Solution
{
public:
    int gcd[15][15];
    int dp[1 << 14];
    int fn(int mask, int n)
    {
        if (mask == 0)
            return 0;

        int i = n - __builtin_popcount(mask) / 2 + 1;

        if (dp[mask] != -1)
            return dp[mask];
        int res = 0;

        int x = mask;
        while (x)
        { // JUST RUNNING OPTIMAL LOOP FOR ALL THE SUBMASKS WITH ONLY
          // 2 BITS SETS
            int b1 = __builtin_ctz(x);
            int y = (x & (x - 1));
            while (y)
            {
                int b2 = __builtin_ctz(y);
                int sub = ((1 << b1) | (1 << b2));

                res = max(res, i * gcd[b1][b2] + fn(mask ^ sub, n));
                y &= (y - 1);
            }
            x &= (x - 1);
        }
        return dp[mask] = res;
    }
    int maxScore(vector<int> &nums)
    {
        int n = nums.size();
        int full = (1 << n) - 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                gcd[i][j] = gcd[j][i] = __gcd(nums[i], nums[j]);
            }
        }
        // memset(dp,-1,sizeof(dp));
        // return fn(full,n/2);

        dp[0] = 0;
        for (int mask = 1; mask <= full; mask++)
        {
            if (__builtin_popcount(mask) & 1)
                continue;

            int i = n / 2 - __builtin_popcount(mask) / 2 + 1;

            int res = 0;

            int x = mask;
            while (x)
            { // JUST RUNNING OPTIMAL LOOP FOR ALL THE SUBMASKS WITH
              // ONLY 2 BITS SETS
                int b1 = __builtin_ctz(x);
                int y = (x & (x - 1));
                while (y)
                {
                    int b2 = __builtin_ctz(y);
                    int sub = ((1 << b1) | (1 << b2));

                    res = max(res, i * gcd[b1][b2] + dp[mask ^ sub]);
                    y &= (y - 1);
                }
                x &= (x - 1);
            }
            dp[mask] = res;
        }
        return dp[full];
    }
};