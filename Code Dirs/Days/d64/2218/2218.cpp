// Link: https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k)  SC: O(k)
// Approach: We can use dynamic programming to solve this problem. We can create a 1D array dp where dp[i] represents the maximum value of coins that can be obtained by taking i coins from the piles. We can iterate through the piles and for each pile, we can iterate through the coins in the pile and update the dp array. Finally, we return dp[k] which represents the maximum value of coins that can be obtained by taking k coins from the piles.
class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        static int cur[2001]{}, nxt[2001]{};
        memset(cur, 0, sizeof(int) * (k + 1));
        memset(nxt, 0, sizeof(int) * (k + 1));
        for (const vector<int> &p : piles)
        {
            for (int i{0}, sum{0}; i < p.size(); ++i)
            {
                sum += p[i];
                const int cnt{i + 1};
                for (int i{cnt}; i <= k; ++i)
                {
                    nxt[i] = max(nxt[i], cur[i - cnt] + sum);
                }
            }
            memcpy(cur, nxt, sizeof(int) * (k + 1));
        }
        return cur[k];
    }
};