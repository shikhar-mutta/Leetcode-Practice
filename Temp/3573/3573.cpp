// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*log(max-min)) SC: O(1)
// Approach: Binary search on the penalty value. For each penalty value, we can use a DP approach to find the maximum profit and the number of transactions used to achieve that profit. If the number of transactions is less than or equal to k, we can try to reduce the penalty to fill up k transactions. Otherwise, we need to increase the penalty to reduce the number of transactions.
class Solution
{
public:
    long long maximumProfit(vector<int> &prices, int k)
    {
        long long l = 0, r = 1e9 + 7, ans = 0;
        int n = prices.size();

        while (l <= r)
        {
            long long mid = (r + l) / 2;

            // State: {profit, -transaction_count}
            // Note: We use negative count so std::max prefers FEWER
            // transactions when profits are equal (this helps strict binary
            // search bounding).

            pair<long long, int> neutral = {0, 0};
            pair<long long, int> held = {-prices[0], 0};
            pair<long long, int> shorted = {prices[0], 0};

            for (int i = 1; i < n; ++i)
            {
                pair<long long, int> next_neutral = max(
                    {neutral,
                     {held.first + prices[i] - mid, held.second - 1},
                     {shorted.first - prices[i] - mid, shorted.second - 1}});

                // Open Long or Keep Holding
                pair<long long, int> next_held =
                    max(held, {neutral.first - prices[i], neutral.second});

                // Open Short or Keep Shorting
                pair<long long, int> next_shorted =
                    max(shorted, {neutral.first + prices[i], neutral.second});

                neutral = next_neutral;
                held = next_held;
                shorted = next_shorted;
            }

            // -neutral.second is the actual count of transactions
            if (-neutral.second <= k)
            {
                ans = neutral.first + mid * k;
                r = mid - 1; // Try to reduce penalty to fill up k transactions
            }
            else
            {
                l = mid + 1; // Too many transactions, increase penalty
            }
        }
        return ans;
    }
};