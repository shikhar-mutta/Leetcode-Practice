// Link: https://leetcode.com/problems/profitable-schemes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(crimes * n * minProfit)  SC: O(n * minProfit)
//  Approach: 0/1 knapsack DP over (membersUsed, profitAchieved), capping
//  profit at minProfit (any profit >= minProfit counts the same). For
//  each crime, iterate members/profit downward to avoid reuse.
//  dp[m][p] = number of schemes using exactly m members with profit
//  capped-at p; answer sums dp[m][minProfit] over all m.
const int MOD = 1e9 + 7;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
const int N = 105;
long long dp[N][N]; // dp[mem][p] là số cách chọn schemes sử dụng 'mem' người và
                    // đạt tối thiểu 'p' profit
class Solution
{
public:
    void add(long long &x, const int y)
    {
        x += y;
        if (x >= MOD)
            x -= MOD;
    }

    int profitableSchemes(int n, int minProfit, vector<int> &group,
                          vector<int> &profit)
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        FOR(i, 0, group.size() - 1)
        {
            int member = group[i];
            int p_gain = profit[i];

            FORD(mem, n, member)
            {
                FORD(p, minProfit, 0)
                {
                    int prev_prof = max(0, p - p_gain);
                    add(dp[mem][p], dp[mem - member][prev_prof]);
                }
            }
        }

        long long ans = 0;
        FOR(mem, 0, n)
        add(ans, dp[mem][minProfit]);

        return ans;
    }
};