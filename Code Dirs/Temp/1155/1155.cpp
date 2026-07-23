// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    vector<vector<int>> dp;
    int find(int n, int k, int target)
    {1155_driver.cpp 1155_expected.txt 1155_input.txt 1155.cpp
        if (n == 0)
            return (target == 0);
        if (target < n || target > k * n)
            return 0;
        if (dp[n][target] != -1)
            return dp[n][target];
        long long ways = 0;
        for (int i = 1; i <= k; i++)
        {
            if (target >= i)
            {
                ways = (ways + find(n - 1, k, target - i)) % MOD;
            }
        }
        return dp[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        dp.assign(n + 1, vector<int>(target + 1, -1));
        return find(n, k, target);
    }
};