// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: We can use a greedy approach to solve this problem. We can keep track of the
    // maximum profit we can make by buying and selling the stock at most twice. We can do this
    // by keeping track of the maximum profit we can make after each action (buying or selling)
    // while scanning the prices from left to right.
    int maxProfit(vector<int> &prices)
    {
        // Best profit so far after each action, scanning left to right:
        int buy1 = INT_MIN; // holding 1st stock      (= -buy price)
        int sell1 = 0;      // sold 1st stock
        int buy2 = INT_MIN; // holding 2nd stock      (= sell1 - buy price)
        int sell2 = 0;      // sold 2nd stock
        for (int p : prices)
        {
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2; // fewer transactions covered (buy=sell same day = no-op)
    }
};
