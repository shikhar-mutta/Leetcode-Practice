// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: base profit = sum(strategy[i]*prices[i]). For each window of
// size k, replacing it changes its contribution to sum(prices in the
// second half) (first half becomes 0, second half becomes 1). Slide a
// window computing gain = newContribution - oldContribution via prefix
// sums, take the best (>=0, since modification is optional) and add to
// base profit.
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefPrice(n + 1, 0), prefOld(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefPrice[i+1] = prefPrice[i] + prices[i];
            prefOld[i+1] = prefOld[i] + (long long)strategy[i] * prices[i];
        }

        long long base = prefOld[n];
        long long bestGain = 0;
        int half = k / 2;
        for (int start = 0; start + k <= n; start++) {
            long long oldContribution = prefOld[start + k] - prefOld[start];
            long long newContribution = prefPrice[start + k] - prefPrice[start + half];
            bestGain = max(bestGain, newContribution - oldContribution);
        }
        return base + bestGain;
    }
};
