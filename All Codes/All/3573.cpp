// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = LLONG_MIN / 2;
        int n = prices.size();
        vector<long long> closed(k+1, NEG), longOpen(k+1, NEG), shortOpen(k+1, NEG);
        closed[0] = 0;

        for (int day = 0; day < n; day++) {
            long long p = prices[day];
            vector<long long> newClosed = closed, newLong = longOpen, newShort = shortOpen;

            for (int j = 1; j <= k; j++) {
                if (closed[j-1] > NEG) {
                    newLong[j] = max(newLong[j], closed[j-1] - p);
                    newShort[j] = max(newShort[j], closed[j-1] + p);
                }
            }
            for (int j = 1; j <= k; j++) {
                if (longOpen[j] > NEG) newClosed[j] = max(newClosed[j], longOpen[j] + p);
                if (shortOpen[j] > NEG) newClosed[j] = max(newClosed[j], shortOpen[j] - p);
            }

            closed = newClosed;
            longOpen = newLong;
            shortOpen = newShort;
        }

        long long best = 0;
        for (int j = 0; j <= k; j++) best = max(best, closed[j]);
        return best;
    }
};
