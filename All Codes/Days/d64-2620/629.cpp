// Link: https://leetcode.com/problems/k-inverse-pairs-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)  SC: O(n*k)
//  Approach: dp[i][j] = number of permutations of 1..i with exactly j
//  inverse pairs; placing element i can add 0..i-1 inverse pairs, so
//  dp[i][j] = sum_{d=0}^{i-1} dp[i-1][j-d]. Maintain a running window
//  sum (prefix sums) so each transition is O(1), giving O(n*k) overall.
static int dp[1001][1001];
class Solution
{
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k)
    {
        sieve();
        return dp[n][k];
    }

private:
    void sieve()
    {
        // bradar pls 0ms or i commit making halland shoot in my own face
        if (dp[1][0] == 1)
        {
            return;
        }
        dp[1][0] = 1;
        for (int i = 2; i <= 1000; i++)
        {
            long long compute = 0;
            for (int j = 0; j <= 1000; j++)
            {
                compute += dp[i - 1][j];
                if (j >= i)
                {
                    compute -= dp[i - 1][j - i];
                }
                dp[i][j] = compute % MOD;
            }
        }
    }
};