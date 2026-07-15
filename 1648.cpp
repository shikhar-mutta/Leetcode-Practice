// Link: https://leetcode.com/problems/sell-diminishing-valued-colored-balls/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogm) where n is the size of inventory and m is the maximum value in inventory
// SC: O(1) as we are using a constant space
// Approach:
//  1. We can use binary search to find the maximum value of m such that we  can sell all the balls with value greater than m and still have enough balls to sell.
class Solution
{
public:
    int M = 1e9 + 7;
    typedef long long ll;

    bool isValid(ll m, vector<int> &inventory, int k)
    {
        ll balls = 0;
        int n = inventory.size();
        for (int i = 0; i < n; i++)
        {
            balls = balls + max((ll)inventory[i] - m, 0LL);
            if (balls > k)
            {
                return false;
            }
        }
        return true;
    }

    int maxProfit(vector<int> &inventory, int orders)
    {
        int n = inventory.size();
        ll l = 0;
        ll r = *max_element(inventory.begin(), inventory.end());
        ll best_m = 0;

        while (l <= r)
        {
            ll m = l + (r - l) / 2;

            if (isValid(m, inventory, orders))
            {
                best_m = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }

        ll ans = 0;
        ll balls_taken = 0;
        ll sum_tillm = ((best_m * (best_m + 1)) / 2) % M;

        for (int i = 0; i < n; i++)
        {
            ll val = inventory[i];
            if (val > best_m)
            {
                ll total_sum = ((val * (val + 1)) / 2) % M;
                ll current_profit = (total_sum - sum_tillm + M) % M;
                ans = (ans + current_profit) % M;
                balls_taken += (val - best_m);
            }
        }

        ans = (ans + (orders - balls_taken) * best_m) % M;

        return (int)ans;
    }
};