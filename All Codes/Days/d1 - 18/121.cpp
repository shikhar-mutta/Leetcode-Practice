// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int i = 0, n = prices.size();
        long long maxProfit = 0;
        while (i < n)
        {
            if (prices[i] < minPrice)
                minPrice = prices[i];
            maxProfit = max(maxProfit, 1ll * (prices[i] - minPrice));
            i++;
        }
        return maxProfit;
    }
};