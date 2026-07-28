// Link: https://leetcode.com/problems/maximum-weighted-k-edge-path/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * E * t/64) SC: O(n * t/64)
//  Approach: Use a bitset to represent achievable path sums. For each edge count e (1..k), update the bitset for each node based on its neighbors.
// The bitset allows us to efficiently track which path sums are achievable without needing to store all possible sums explicitly. After processing all edges for k steps, we check the bitsets for each node to find the maximum achievable sum less than t.
class Solution
{
public:
    int maxWeight(int n, std::vector<std::vector<int>> &edges, int k, int t)
    {
        std::vector<std::bitset<600>> dp(n);
        for (int u = 0; u < n; ++u)
        {
            dp[u].set(0);
        }
        for (int i = 0; i < k; ++i)
        {
            std::vector<std::bitset<600>> next_dp(n);
            bool found = false;
            for (const auto &edge : edges)
            {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];

                if (dp[u].any())
                {
                    next_dp[v] |= (dp[u] << w);
                    found = true;
                }
            }
            dp = std::move(next_dp);
            if (!found)
                break;
        }

        int max_s = -1;
        for (int u = 0; u < n; ++u)
        {
            for (int s = t - 1; s > max_s; --s)
            {
                if (dp[u].test(s))
                {
                    max_s = s;
                    break;
                }
            }
        }

        return max_s;
    }
};