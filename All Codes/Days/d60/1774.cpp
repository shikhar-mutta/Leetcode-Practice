// Link: https://leetcode.com/problems/closest-dessert-cost/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * 2), SC: O(n * m)
// Approach: Dynamic Programming
// 1. We can use a dynamic programming approach to solve this problem.
// 2. We can create a boolean array dp where dp[i] is true if we can make a dessert with cost i.
// 3. We can initialize dp with the base costs and then iterate through the topping costs and update dp accordingly.
// 4. Finally, we can iterate through dp to find the closest cost to the target and return it.
class Solution
{
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts,
                    int target)
    {
        static const int MAX_COUNT = 2;

        const auto max_base = *max_element(cbegin(baseCosts), cend(baseCosts));
        const auto max_topping =
            *max_element(cbegin(toppingCosts), cend(toppingCosts));
        vector<bool> dp(max(max_base, target + max_topping / 2) + 1);
        for (const auto &b : baseCosts)
        {
            dp[b] = true;
        }
        for (const auto &t : toppingCosts)
        {
            for (int count = 0; count < MAX_COUNT; ++count)
            {
                for (int i = size(dp) - 1 - t; i >= 1; --i)
                {
                    if (dp[i])
                    {
                        dp[i + t] = true;
                    }
                }
            }
        }
        int result = numeric_limits<int>::max();
        for (int i = 1; i <= size(dp) - 1; ++i)
        {
            if (!dp[i])
            {
                continue;
            }
            if (abs(i - target) < abs(result - target))
            {
                result = i;
            }
            if (i >= target)
            {
                break;
            }
        }
        return result;
    }
};
