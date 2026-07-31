// Link: https://leetcode.com/problems/number-of-beautiful-partitions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*K), SC: O(N*K)
// Approach: dp[j][i] = ways to split first i chars into j valid parts. A new part [i', i) is
// valid if s[i'] is prime, s[i-1] is not prime, and i-i'>=minLength. Maintain a running prefix
// sum of dp[j-1][i'] over valid i' as i grows, avoiding an O(N) inner scan.
class Solution
{
public:
    int beautifulPartitions(string s, int k, int minLength)
    {
        int n = s.size();
        auto isPrime = [](char c)
        { return c == '2' || c == '3' || c == '5' || c == '7'; };
        if (!isPrime(s[0]) || isPrime(s[n - 1]))
            return 0;
        if ((long long)k * minLength > n)
            return 0;

        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, 0));
        dp[0][0] = 1;

        for (int j = 1; j <= k; j++)
        {
            long long running = 0;
            for (int i = 0; i <= n; i++)
            {
                int iPrime = i - minLength;
                if (iPrime >= 0 && isPrime(s[iPrime]))
                    running = (running + dp[j - 1][iPrime]) % MOD;
                if (i >= 1 && !isPrime(s[i - 1]))
                    dp[j][i] = running;
            }
        }
        return (int)dp[k][n];
    }
};
