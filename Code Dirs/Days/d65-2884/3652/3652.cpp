// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long original = 0;
        for (int i = 0; i < n; i++) original += (long long)strategy[i] * prices[i];

        vector<long long> prefPrice(n + 1, 0), prefContrib(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefPrice[i+1] = prefPrice[i] + prices[i];
            prefContrib[i+1] = prefContrib[i] + (long long)strategy[i] * prices[i];
        }

        long long bestDelta = 0;
        int half = k / 2;
        for (int l = 0; l + k <= n; l++) {
            int mid = l + half;
            int r = l + k;
            long long newContrib = prefPrice[r] - prefPrice[mid];
            long long oldContrib = prefContrib[r] - prefContrib[l];
            long long delta = newContrib - oldContrib;
            bestDelta = max(bestDelta, delta);
        }

        return original + bestDelta;
    }
};
