// Link: https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(steps * min(steps, arrLen))  SC: O(min(steps, arrLen))
// Approach: DP. Let dp[i][j] = number of ways to reach position j after i steps. Then dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1]. We can optimize the space complexity by only keeping track of the previous row of the DP table.
// Note that we only need to consider positions up to min(steps, arrLen) since we cannot move beyond that in the given number of steps.
class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        vector<int> dp = {1};
        int MOD = 1000000007;
        for (int i = 0; i <= steps; i++)
        {
            long prv = 0, cur = dp[0], nxt = 0;
            int n = dp.size();
            for (int j = 0; j < n; j++)
            {
                nxt = (j >= n - 2) ? 0 : dp[j + 1];
                long a = (prv + cur + nxt) % MOD;
                dp[j] = a;
                prv = cur;
                cur = nxt;
            }
            if (i + 1 <= arrLen)
                dp.push_back(prv);
        }
        return dp[0];
    }
};
