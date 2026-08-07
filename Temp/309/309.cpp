// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track 3 states - hold (own stock), sold (just sold, cooldown next),
// rest (not holding, no cooldown); transition each day
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int hold = -prices[0], sold = 0, rest = 0;
        for (int i = 1; i < (int)prices.size(); i++) {
            int prevHold = hold, prevSold = sold, prevRest = rest;
            hold = max(prevHold, prevRest - prices[i]);
            sold = prevHold + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sold, rest);
    }
};
