// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k), SC: O(k)
// Approach: We can use a greedy approach to solve this problem. We can keep track of the
// maximum profit we can make by buying and selling the stock at most k times. We can do this
// by keeping track of the maximum profit we can make after each action (buying or selling)
// while scanning the prices from left to right. We can use two arrays to keep track of the
// maximum profit we can make after each action (buying or selling) for each transaction.
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        // Same chained states as Stock III, generalized to k pairs:
        // buy[t] = best balance holding the t-th stock, sell[t] = after selling it
        int n = prices.size();
        k = min(k, n / 2); // a transaction needs 2 days; extra k is useless
        if (k == 0)
            return 0;
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int p : prices)
            for (int t = 1; t <= k; t++)
            {
                buy[t] = max(buy[t], sell[t - 1] - p);
                sell[t] = max(sell[t], buy[t] + p);
            }
        return sell[k];
    }
};
