// Link: https://leetcode.com/problems/race-car/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(target log(target))  SC: O(target)
//  Approach: dynamic programming. dp[t] = min instructions to reach exactly t.
//  For each t, try every "accelerate n steps then flip" strategy: drive
//  forward 2^n-1 (n A's) then either stop exactly there (if t==2^n-1,
//  cost n), or flip and continue toward the remainder (2^n-1-t) with an
//  extra reverse move (n+1), or overshoot to 2^n-1+m and flip back
//  toward t-(2^n-1+m)... simplified to the two dominant cases per n.
class Solution
{
public:
    int racecar(int target)
    {
        vector<int> dp(target + 1);

        for (int i = 1; i <= target; i++)
        {
            int k = 32 - __builtin_clz(i);

            if (i == (1 << k) - 1)
            {
                dp[i] = k;
                continue;
            }

            // Overshoot and come back
            dp[i] = k + 1 + dp[(1 << k) - 1 - i];

            // Stop before overshooting, reverse twice
            for (int j = 0; j < k - 1; j++)
            {
                dp[i] = min(dp[i], (k - 1) + 1 + j + 1 +
                                       dp[i - ((1 << (k - 1)) - (1 << j))]);
            }
        }

        return dp[target];
    }
};