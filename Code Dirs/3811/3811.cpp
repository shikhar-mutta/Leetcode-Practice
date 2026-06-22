// Link: https://leetcode.com/problems/number-of-alternating-xor-partitions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)  SC: O(1)
    // dp1[i] = count of partitions of prefix[0..i-1] with last block XOR = t1
    // dp2[i] = count of partitions of prefix[0..i-1] with last block XOR = t2
    int alternatingXOR(vector<int> &nums, int t1, int t2)
    {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int cx = 0;         // cx = cumulative XOR of prefix
        int t1t2 = t1 ^ t2; // Precompute cumulative sums for dp1 and dp2 states:

        long long sum1_t1 = 0, sum1_t2 = 0;
        long long sum2_0 = 1, sum2_t1t2 = 0;

        long long dp1 = 0, dp2 = 0;
        // dp1[i] = count of partitions of prefix[0..i-1] with last block XOR = t1
        // dp2[i] = count of partitions of prefix[0..i-1] with last block XOR = t2

        for (int i = 1; i <= n; i++)
        {
            cx ^= nums[i - 1];
            dp1 = 0;
            dp2 = 0;

            // dp1[i] = sum2[cx ^ t1]:  cx^t1==0 → cx==t1 ; cx^t1==t1t2 → cx==t2
            if (cx == t1) // cx^t1==0 → cx==t1
                dp1 = sum2_0;
            else if (cx == t2) // cx^t1==t1t2 → cx==t2
                dp1 = sum2_t1t2;

            // dp2[i] = sum1[cx ^ t2]:  cx^t2==t1 → cx==t1t2 ; cx^t2==t2 → cx==0
            if (cx == t1t2) // cx^t2==t1 → cx==t1t2
                dp2 = sum1_t1;
            else if (cx == 0) // cx^t2==t2 → cx==0
                dp2 = sum1_t2;

            // Update accumulators AFTER computing dp values
            if (cx == t1) // Update sum1_t1 for dp1 states where last block XOR = t1
                sum1_t1 = (sum1_t1 + dp1) % MOD;
            if (cx == t2) // Update sum1_t2 for dp1 states where last block XOR = t2
                sum1_t2 = (sum1_t2 + dp1) % MOD;
            if (cx == 0) // Update sum2_0 for dp2 states where last block XOR = 0
                sum2_0 = (sum2_0 + dp2) % MOD;
            if (cx == t1t2) // Update sum2_t1t2 for dp2 states where last block XOR = t1^t2
                sum2_t1t2 = (sum2_t1t2 + dp2) % MOD;
        }

        return (dp1 + dp2) % MOD;
    }
};
