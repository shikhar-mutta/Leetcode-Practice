// Link: https://leetcode.com/problems/number-of-ways-to-earn-points/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*target), SC: O(target)
//  Approach: We can use a dynamic programming approach to solve this problem. We can use a dp array where dp[i] represents the number of ways to earn i points. We can iterate through each type of question and for each type, we can iterate through the dp array and update the number of ways to earn points by adding the number of ways to earn points from the previous types of questions
class Solution
{
public:
    int waysToReachTarget(int target, vector<vector<int>> &types)
    {
        int n = types.size();
        const int mod = 1e9 + 7;
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (auto it : types)
        {
            vector<long long> ndp(dp);
            int val = it[1];
            int cnt = it[0];
            if (val == 0)
            {
                for (int sum = 0; sum <= target; sum++)
                {
                    ndp[sum] = (dp[sum] * (cnt + 1)) % mod;
                }
                dp.swap(ndp);
                continue;
            }
            else
            {
                for (int rem = 0; rem < val; rem++)
                {
                    long long wind = 0;
                    for (int sum = rem, k = 0; sum <= target; sum += val, k++)
                    {
                        wind = (wind + dp[sum]) % mod;
                        if (k > cnt)
                        {
                            wind =
                                (wind - dp[sum - (cnt + 1) * val] + mod) % mod;
                        }
                        ndp[sum] = wind;
                    }
                }
            }
            dp.swap(ndp);
        }
        return dp[target];
    }
};
