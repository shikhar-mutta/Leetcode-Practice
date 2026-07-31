// Link: https://leetcode.com/problems/minimum-xor-sum-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*2^n)  SC: O(2^n)
//  Approach: Use dynamic programming with bitmasking to find the minimum XOR sum of two arrays. We maintain a dp array where dp[mask] represents the minimum XOR sum for the subset of nums2 represented by the bitmask 'mask'. For each mask, we calculate the number of elements already chosen (using __builtin_popcount) and try to pair the next element from nums1 with each unchosen element from nums2, updating the dp array accordingly. The final answer is found in dp[(1 << n) - 1], which represents the minimum XOR sum when all elements from nums2 have been paired with elements from nums1.
class Solution
{
public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        const int INF = 1e9;
        int dp[(1 << 20) + 5];
        fill(dp, dp + (1 << n), INF);
        int cost[20][20];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cost[i][j] = nums1[i] ^ nums2[j];
            }
        }
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[mask] == INF)
                continue;
            int i = __builtin_popcount(mask);
            for (int j = 0; j < n; j++)
            {
                if (!((mask >> j) & 1))
                {
                    int nm = mask | (1 << j);
                    dp[nm] = min(dp[nm], dp[mask] + cost[i][j]);
                }
            }
        }
        return dp[(1 << n) - 1];
    }
};