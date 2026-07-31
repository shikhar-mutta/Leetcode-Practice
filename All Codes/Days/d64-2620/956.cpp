// Link: https://leetcode.com/problems/tallest-billboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sum)  SC: O(sum)
//  Approach: dp[diff] = max sum of rods that can be used to achieve a difference of diff between the two billboards. For each rod, we can either add it to the first billboard, add it to the second billboard, or not use it at all. We update the dp array accordingly. The answer is dp[0], which represents the maximum sum of rods that can be used to achieve a difference of 0 between the two billboards.
class Solution
{
public:
    static int32_t tallestBillboard(const vector<int32_t> &rods) noexcept
    {
        const int32_t sum(accumulate(rods.begin(), rods.end(), 0));

        vector<int16_t> dp(sum + 1, -1), prev(dp);
        dp[0] = 0;
        prev[0] = 0;
        for (auto &&rod : rods)
        {
            swap(dp, prev);
            const uint32_t maxdiff(sum - rod);
            for (int32_t diff(0); diff <= maxdiff; ++diff)
            {
                if (prev[diff] < 0)
                    continue;

                dp[diff] = max(dp[diff], prev[diff]);
                uint32_t k(diff + rod);
                if (prev[diff] > dp[k])
                    dp[k] = prev[diff];
                k = abs(diff - rod);
                dp[k] = max(static_cast<int16_t>(dp[k]),
                            static_cast<int16_t>(prev[diff] + min(diff, rod)));
            }
        }

        return dp[0];
    }
};