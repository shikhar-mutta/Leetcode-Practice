// Link: https://leetcode.com/problems/valid-permutations-for-di-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
//  Approach: dp[i][j] = number of valid permutations of first i+1 elements where last element is j-th smallest.
//  If S[i] == 'I', then dp[i+1][j] = sum(dp[i][k]) for k < j, else dp[i+1][j] = sum(dp[i][k]) for k > j. Use prefix sums to compute these sums efficiently.
class Solution
{
public:
    int numPermsDISequence(string S)
    {
        int n = S.length(), mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int j = 0; j <= n; j++)
            dp[0][j] = 1;
        for (int i = 0; i < n; i++)
            if (S[i] == 'I')
                for (int j = 0, cur = 0; j < n - i; j++)
                    dp[i + 1][j] = cur = (cur + dp[i][j]) % mod;
            else
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    dp[i + 1][j] = cur = (cur + dp[i][j + 1]) % mod;
        return dp[n][0];
    }
};