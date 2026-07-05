// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: We can use a state machine to solve this problem. We can keep track of the
    // maximum profit we can make after each action (holding, selling, or resting) while
    // scanning the prices from left to right. We can use three variables to keep track of the
    // maximum profit we can make after each action (holding, selling, or resting).
    int maxProfit(vector<int> &prices)
    {
        // State machine per day:
        //   hold: holding a stock
        //   sold: sold today (tomorrow is cooldown)
        //   rest: no stock, free to buy (idle or past cooldown)
        int hold = INT_MIN, sold = INT_MIN, rest = 0;
        for (int p : prices)
        {
            int prevSold = sold;
            sold = hold + p;            // sell what we held
            hold = max(hold, rest - p); // keep holding, or buy (needs rest)
            rest = max(rest, prevSold); // idle, or cooldown day ends
        }
        return max(sold, rest); // never end while holding
    }
};
