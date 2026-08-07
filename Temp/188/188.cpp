// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(k)
// Approach: DP generalizing the "at most 2 transactions" trick to k — buy[j]/sell[j] track best profit
// after at most j buy/sell pairs, updated in increasing j order each day
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty() || k == 0) return 0;
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);
        for (int p : prices) {
            for (int j = 1; j <= k; j++) {
                buy[j] = max(buy[j], sell[j-1] - p);
                sell[j] = max(sell[j], buy[j] + p);
            }
        }
        return sell[k];
    }
};
