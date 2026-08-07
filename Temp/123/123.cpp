// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: track 4 running states (buy1, sell1, buy2, sell2) for at most two transactions, updating each in order
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for (int p : prices) {
            buy1 = max(buy1, -p);
            sell1 = max(sell1, buy1 + p);
            buy2 = max(buy2, sell1 - p);
            sell2 = max(sell2, buy2 + p);
        }
        return sell2;
    }
};
