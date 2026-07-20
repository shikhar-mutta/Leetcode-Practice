// Link: https://leetcode.com/problems/maximum-number-of-items-from-sale-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * budget + n * max_f) where n is the number of items, budget is the given budget, and max_f is the maximum frequency of items.
    // SC: O(budget + max_f) where budget is the given budget and max_f is the maximum frequency of items.
    // Approach:
    // 1. Find the minimum price and maximum frequency of items.
    // 2. Create a frequency array to count the number of items for each frequency.
    // 3. Use dynamic programming to calculate the maximum number of items that can be bought.
    // 4. Finally, calculate the maximum number of items that can be bought within the budget.
    int maximumSaleItems(vector<vector<int>> &items, int budget)
    {
        int min_p = 1e9;
        int max_f = 0;
        for (auto &it : items)
        {
            min_p = min(min_p, it[1]);
            max_f = max(max_f, it[0]);
        }
        vector<int> freq(max_f + 1, 0);
        for (auto &x : items)
        {
            freq[x[0]]++;
        }
        vector<int> dp(budget + 1, -1);
        dp[0] = 0;
        for (auto &it : items)
        {
            int f = it[0];
            int p = it[1];
            int val = 0;
            for (int i = f; i <= max_f; i += f)
            {
                val += freq[i];
            }
            for (int w = budget; w >= p; w--)
            {
                if (dp[w - p] != -1)
                {
                    dp[w] = max(dp[w - p] + val, dp[w]);
                }
            }
        }
        int copies = 0;
        for (int i = 0; i <= budget; i++)
        {
            if (dp[i] != -1)
            {
                copies = max(copies, dp[i] + (budget - i) / min_p);
            }
        }
        return copies;
    }
};