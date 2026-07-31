// Link: https://leetcode.com/problems/paint-house-iv/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: pair up house i with its mirror n-1-i (must differ in color).
//  Process i from 0 upward, keeping dp[c1][c2] = min cost so far with
//  house i colored c1 and its mirror colored c2 (c1 != c2), enforcing the
//  usual adjacent-houses-differ rule on both sides each step. If n is odd
//  there's one middle house left over; its color is forced to be whichever
//  of the 3 colors isn't c1 or c2 (it's adjacent to both).
using ll = long long;
class Solution
{
public:
    long long minCost(int n, vector<vector<int>> &cost)
    {
        ll dp[6]; // 0 = 0 1 , 1 3 5
                  // 1 = 1 2 , 0 4 5
                  // 2 = 0 2 , 3 4 5
                  // 3 = 1 0 , 0 2 4
                  // 4 = 2 1 , 1 2 3
                  // 5 = 2 0 , 0 1 2
        memset(dp, 0, sizeof(dp));
        ll l = 0, r = n - 1;
        ll ans = 1e18;
        while (l < r)
        {
            ll ndp[6];
            memset(ndp, 0, sizeof(ndp));
            ndp[0] = cost[l][0] + cost[r][1] + min(dp[1], min(dp[3], dp[5]));
            ndp[1] = cost[l][1] + cost[r][2] + min(dp[0], min(dp[4], dp[5]));
            ndp[2] = cost[l][0] + cost[r][2] + min(dp[3], min(dp[4], dp[5]));
            ndp[3] = cost[l][1] + cost[r][0] + min(dp[0], min(dp[2], dp[4]));
            ndp[4] = cost[l][2] + cost[r][1] + min(dp[1], min(dp[2], dp[3]));
            ndp[5] = cost[l][2] + cost[r][0] + min(dp[0], min(dp[1], dp[2]));
            for (ll i = 0; i < 6; i++)
                dp[i] = ndp[i];
            l++;
            r--;
        }
        for (ll i = 0; i < 6; i++)
            ans = min(dp[i], ans);
        return ans;
    }
};