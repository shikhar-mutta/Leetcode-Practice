// Link: https://leetcode.com/problems/count-the-number-of-inversions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * maxK)  SC: O(maxK)
//  Approach: dp[k] = number of ways to arrange the first i+1 elements
//  (building the permutation by inserting values 0..i one at a time) with
//  exactly k inversions. Inserting the i-th element can add 0..i new
//  inversions, so dp'[k] = sum_{j=0}^{min(i,k)} dp[k-j], computed via a
//  prefix-sum sliding window in O(1) per k. After processing index i, if a
//  requirement fixes inversions at i, zero out all dp[k] except that k.
class Solution
{
public:
    int numberOfPermutations(int n, vector<vector<int>> &reqs)
    {
        sort(begin(reqs), end(reqs));
        int dp[2][401] = {1}, prev = 0, j = 0, mod = 1000000007;
        for (int N = 1; N <= n; ++N)
        {
            for (int K = prev; K <= reqs[j][1]; ++K)
            {
                dp[N % 2][K] =
                    (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % mod;
                if (K >= N)
                    dp[N % 2][K] =
                        (mod + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % mod;
            }
            if (N - 1 == reqs[j][0])
            {
                fill_n(begin(dp[0]) + prev, reqs[j][1] - prev, 0);
                fill_n(begin(dp[1]) + prev, reqs[j][1] - prev, 0);
                prev = reqs[j++][1];
            }
        }
        return dp[n % 2][reqs.back()[1]];
    }
};