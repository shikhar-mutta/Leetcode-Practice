// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track cash (max profit holding no stock) and hold (max profit holding stock); update both each day.
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < (int)prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
