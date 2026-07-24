// Link: https://leetcode.com/problems/maximum-profit-of-operating-a-centennial-wheel/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    //  Approach:
    //    1. We will maintain a variable to keep track of the number of waiting customers.
    //    2. We will iterate through the customers array and for each customer,
    //       we will add the number of waiting customers to the current customer and calculate the profit
    //       for the current rotation. We will keep track of the maximum profit and the number of rotations required to achieve that profit.
    //    3. If the maximum profit is greater than 0, we will return the number of rotations required to achieve that profit, otherwise we will return -1.
    //    4. We will continue this process until we have processed all customers and there are no more waiting customers.
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost,
                               int runningCost)
    {
        int waiting = 0;
        int profit = 0, maxProfit = 0;
        int ans = -1;
        int rotations = 0;
        int i = 0;
        int n = customers.size();

        while (i < n || waiting > 0)
        {

            // add arriving customers
            if (i < n)
            {
                waiting += customers[i];
                i++;
            }

            // board people
            int board = min(4, waiting);
            waiting -= board;

            rotations++;

            // update profit
            profit += board * boardingCost - runningCost;

            // check max profit
            if (profit > maxProfit)
            {
                maxProfit = profit;
                ans = rotations;
            }
        }

        return maxProfit > 0 ? ans : -1;
    }
};
