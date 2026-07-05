// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: We can use a state machine to solve this problem. We can keep track of the
    // maximum profit we can make after each action (holding, selling, or resting) while
    // scanning the prices from left to right. We can use two variables to keep track of the
    // maximum profit we can make after each action (holding, or free).
    int maxProfit(vector<int> &prices, int fee)
    {
        // Two states per day: holding a stock, or free (not holding).
        // Charge the fee once per transaction, on the sell.
        long long hold = INT_MIN, free = 0; // INT_MIN: "unreachable", no underflow in long long
        for (int p : prices)
        {
            long long prevFree = free;
            free = max(free, hold + p - fee); // sell today
            hold = max(hold, prevFree - p);   // buy today
        }
        return (int)free;
    }
};
