// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach:
// 1. We can use dynamic programming to keep track of the maximum achievable sum for each possible remainder when divided by 3 (0, 1, or 2).
// 2. We initialize an array dp of size 3, where dp[r] represents the maximum achievable sum with a remainder of r when divided by 3.
// 3. We iterate through each number in the input array and update the dp array based on the current number and the previous values in dp.
// 4. Finally, we return dp[0], which represents the maximum sum that is divisible by 3.
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        // dp[r] = max achievable sum with sum % 3 == r (LLONG_MIN = unreachable)
        const long long NEG = LLONG_MIN;
        vector<long long> dp = {0, NEG, NEG};
        for (int x : nums)
        {
            auto ndp = dp;
            for (int r = 0; r < 3; r++)
            {
                if (dp[r] == NEG)
                    continue;
                int nr = (r + x) % 3;
                ndp[nr] = max(ndp[nr], dp[r] + x);
            }
            dp = ndp;
        }
        return (int)dp[0];
    }
};
