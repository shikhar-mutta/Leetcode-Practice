// Link: https://leetcode.com/problems/maximum-total-reward-using-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of rewardValues.
    // SC: O(n) where n is the number of rewardValues.
    // Approach:
    //   1. Sort the rewardValues in ascending order.
    //   2. Remove duplicates from the rewardValues.
    //   3. Use dynamic programming to find the maximum total reward.
    //   4. Create a boolean array dp of size 4001 and initialize all elements to false.
    //   5. Set dp[0] to true.
    //   6. For each reward value r in rewardValues, iterate from r to 2*r and update dp[j] to be true if dp[j-r] is true.
    //   7. Finally, iterate from 4000 to 1 and return the first index i where dp[i] is true. This will be the maximum total reward.
    //   8. If no index is found, return 0.
    int maxTotalReward(vector<int> &rewardValues)
    {
        sort(rewardValues.begin(), rewardValues.end());
        rewardValues.erase(
            std::unique(rewardValues.begin(), rewardValues.end()),
            rewardValues.end());
        bool dp[4'001];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (int r : rewardValues)
        {
            for (int j = r; j < 2 * r; j++)
            {
                dp[j] |= dp[j - r];
            }
        }
        for (int i = 4'000; i > 0; i--)
            if (dp[i])
                return i;
        return 0;
    }
};
