// Link: https://leetcode.com/problems/number-of-distinct-roll-sequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Dynamic Programming with precomputation and optimized state transitions
class Solution
{
public:
    int distinctSequences(int n)
    {
        static std::array<int, 10005> ans = {0};
        static bool precomputed = false;

        if (!precomputed)
        {
            ans[1] = 6;
            int mod = 1e9 + 7;

            // Flattened 1D arrays representing a 7x7 grid (Index = row * 7 +
            // col) std::array handles flat memory layout naturally and allows
            // safe, rapid zeroing
            std::array<int, 49> cnt = {0};
            std::array<int, 49> curr = {0};

            // Step 1: Precompute a 1D validity bitmask matrix to eliminate
            // runtime std::gcd overhead mask[i * 7 + j] is true if i and j are
            // distinct and coprime
            std::array<bool, 49> valid_pair = {false};
            for (int i = 1; i <= 6; i++)
            {
                for (int j = 1; j <= 6; j++)
                {
                    if (i != j && std::gcd(i, j) == 1)
                    {
                        valid_pair[i * 7 + j] = true;
                    }
                }
            }

            // Step 2: Base case logic for length = 2
            for (int i = 1; i <= 6; i++)
            {
                for (int j = 1; j <= 6; j++)
                {
                    if (valid_pair[i * 7 + j])
                    {
                        cnt[i * 7 + j] = 1;
                        ans[2] = (ans[2] + 1) % mod;
                    }
                }
            }

            // Step 3: Core Dynamic Programming using optimized lookup masks
            for (int len = 3; len <= 10000; len++)
            {
                curr.fill(0); // Blazing fast replacement for memset() using
                              // compiler builtins

                for (int k = 1; k <= 6; k++)
                {
                    int k_offset = k * 7;

                    for (int i = 1; i <= 6; i++)
                    {
                        // Check if transition from k to i is mathematically
                        // legal
                        if (!valid_pair[k_offset + i])
                            continue;

                        int i_offset = i * 7;
                        int target_idx = k_offset + i;

                        for (int j = 1; j <= 6; j++)
                        {
                            // The dice roll before 'i' cannot be equal to the
                            // new dice roll 'k'
                            if (k == j)
                                continue;

                            curr[target_idx] += cnt[i_offset + j];
                            if (curr[target_idx] >= mod)
                            {
                                curr[target_idx] -=
                                    mod; // Avoid expensive modulo (%) math with
                                         // manual reduction
                            }
                        }
                    }
                }

                // Step 4: Bulk update the main state and accumulate the current
                // length's answer
                cnt = curr; // Fast bitwise array copy executed at the hardware
                            // register level
                for (int idx = 0; idx < 49; idx++)
                {
                    ans[len] += cnt[idx];
                    if (ans[len] >= mod)
                    {
                        ans[len] -= mod;
                    }
                }
            }

            precomputed = true;
        }

        return ans[n];
    }
};