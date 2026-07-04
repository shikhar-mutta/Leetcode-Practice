// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the prices array
    // SC: O(1)
    // Approach: Greedy approach
    int maxProfit(vector<int> &prices)
    {
        // Unlimited transactions => any upward move is collectible:
        // sum of all positive day-to-day differences
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); i++)
            profit += max(0, prices[i] - prices[i - 1]);
        return profit;
    }
};
