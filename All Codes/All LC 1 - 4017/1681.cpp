// Link: https://leetcode.com/problems/minimum-incompatibility/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(2^n * n) where n is the size of the input array
//SC: O(2^n) where n is the size of the input array
//Approach: We can use bitmasking and dynamic programming to solve this problem. We can represent the state of the board using a bitmask, where each bit represents whether a number is present in the board or not. We can precompute all valid groups of size n/k and their costs. Then, we can use dynamic programming to find the minimum cost to fill the board with valid groups. The final answer will be the minimum cost to fill the board with all numbers.   
class Solution
{
public:
    int minimumIncompatibility(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n % k != 0)
            return -1;

        // 1. Pigeonhole Pruning: If a number appears > k times, it's
        // impossible.
        int freq[17] = {0};
        for (int num : nums)
        {
            if (++freq[num] > k)
                return -1;
        }

        int groupSize = n / k;
        int maxMask = 1 << n;
        sort(nums.begin(), nums.end());

        // valid_groups[i] will store all valid subsets where the lowest element
        // is at index 'i'
        vector<int> valid_groups[16];
        int cost[65536];

        // Phase 1: Precompute valid single groups and bucket them by their
        // anchor bit
        for (int mask = 1; mask < maxMask; mask++)
        {
            if (__builtin_popcount(mask) == groupSize)
            {
                int seen = 0;
                bool duplicate = false;

                for (int i = 0; i < n; i++)
                {
                    if ((mask >> i) & 1)
                    {
                        if (seen & (1 << nums[i]))
                        {
                            duplicate = true;
                            break;
                        }
                        seen |= (1 << nums[i]);
                    }
                }

                if (!duplicate)
                {
                    int mn = nums[__builtin_ctz(mask)];
                    int mx = nums[31 - __builtin_clz(mask)];
                    cost[mask] = mx - mn;

                    // The anchor bit of this group is its lowest set bit
                    valid_groups[__builtin_ctz(mask)].push_back(mask);
                }
            }
        }

        int dp[65536];
        for (int i = 0; i < maxMask; i++)
            dp[i] = 1e9;
        dp[0] = 0; // Start at an empty board

        // Phase 2: Push DP
        for (int mask = 0; mask < maxMask; mask++)
        {
            // Massive Pruning: If we haven't reached this state, don't expand
            // from it
            if (dp[mask] == 1e9)
                continue;

            // Find the missing elements (flip the mask)
            int empty_bits = ((1 << n) - 1) ^ mask;
            if (empty_bits == 0)
                continue; // Board is full

            // Find the lowest empty slot (our anchor requirement)
            int anchor_bit = __builtin_ctz(empty_bits);

            // Only attempt to add groups that natively start with our required
            // anchor bit
            for (int sub : valid_groups[anchor_bit])
            {
                // If the group doesn't overlap with what we already have
                if ((mask & sub) == 0)
                {
                    dp[mask | sub] = min(dp[mask | sub], dp[mask] + cost[sub]);
                }
            }
        }

        return dp[maxMask - 1] == 1e9 ? -1 : dp[maxMask - 1];
    }
};