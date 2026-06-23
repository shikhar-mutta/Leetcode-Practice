// Link: https://leetcode.com/problems/partition-array-to-minimize-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2 * k), SC: O(n)
    int minXor(vector<int> &nums, int k)
    {
        int n = nums.size();

        // dp[j] = minimum possible maximum XOR
        // for first j elements using current number of partitions
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // Build answer for 1...k partitions
        for (int part = 1; part <= k; part++)
        {
            // Traverse backwards to preserve previous partition states
            for (int j = n - (k - part); j >= part; j--)
            {
                int best = INT_MAX;
                int xorVal = 0;

                // Try every possible start of the last partition from j-1 --> part-1
                for (int l = j - 1; l >= part - 1; l--)
                {
                    xorVal ^= nums[l]; // XOR of nums[l...j-1]

                    // Cost = max(
                    //          answer for previous partitions,
                    //          XOR of current(last) partition
                    //        )
                    best = min(best, max(dp[l], xorVal));
                }

                dp[j] = best;
            }
        }

        return dp[n];
    }
};

// dfs(i, k) :=  min XOR val  where nums[i~n-1] split into k subarray