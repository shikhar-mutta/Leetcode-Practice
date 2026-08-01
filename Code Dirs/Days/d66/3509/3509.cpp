// Link: https://leetcode.com/problems/maximum-product-of-subsequences-with-an-alternating-sum-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * limit), where n is the length of nums and limit is the maximum value of nums.
// SC: O(n * limit), where n is the length of nums and limit is the maximum value of nums.
// Approach: We can use dynamic programming to find the maximum product of subsequences with an alternating sum equal to k. We will maintain two dp arrays, dp0 and dp1, where dp0[i] represents the maximum product of subsequences ending at an odd index (parity 0 - last operation was subtraction) and dp1[i] represents the maximum product of subsequences ending at an even index (parity 1 - last operation was addition). We will also maintain two bitsets, reach0 and reach1, to track all valid sums regardless of product. We will iterate through the nums array and update the dp arrays and bitsets accordingly. Finally, we will return the maximum valid product starting from the limit and working downwards.
class Solution
{
public:
    int maxProduct(vector<int> &nums, int k, int limit)
    {
        // N <= 150, max val = 12. Mathematically bound to [-900, 900].
        if (k < -900 || k > 900)
        {
            return -1;
        }

        // dp0 tracks subsequences ending at an odd index (parity 0 - last
        // operation was subtraction) dp1 tracks subsequences ending at an even
        // index (parity 1 - last operation was addition) We only allocate
        // exactly what we need for the limit to save microseconds
        vector<bitset<1805>> dp0(limit + 1);
        vector<bitset<1805>> dp1(limit + 1);

        // reach tracks ALL valid sums regardless of product (crucial for
        // salvaging '0's)
        bitset<1805> reach0;
        bitset<1805> reach1;

        for (int x : nums)
        {
            if (x == 0)
            {
                // A zero instantly drops any previously reachable state down to
                // a product of 0
                dp0[0] |= reach1;
                dp1[0] |= reach0;
                dp1[0].set(900); // Standalone sequence of just [0]

                // Update global reachability
                bitset<1805> old_r0 = reach0;
                reach0 |= reach1;
                reach1 |= old_r0;
                reach1.set(900);
            }
            else
            {
                // Reverse in-place DP update: Iterating backwards ensures we
                // don't accidentally chain-multiply states generated in this
                // current step.
                for (int p = limit / x; p >= 0; --p)
                {
                    bitset<1805> new_0 =
                        dp1[p] >> x;                  // Subtract x (shift right)
                    bitset<1805> new_1 = dp0[p] << x; // Add x (shift left)
                    dp0[p * x] |= new_0;
                    dp1[p * x] |= new_1;
                }

                // Start a fresh sequence if within limits
                if (x <= limit)
                {
                    dp1[x].set(900 + x);
                }

                // Update global reachability using native SIMD shifts
                bitset<1805> new_r0 = reach1 >> x;
                bitset<1805> new_r1 = reach0 << x;
                reach0 |= new_r0;
                reach1 |= new_r1;
                reach1.set(900 + x);
            }
        }

        // Find the maximum valid product starting from the limit and working
        // downwards
        int target = 900 + k;
        for (int p = limit; p >= 0; --p)
        {
            if (dp0[p].test(target) || dp1[p].test(target))
            {
                return p;
            }
        }

        return -1;
    }
};
