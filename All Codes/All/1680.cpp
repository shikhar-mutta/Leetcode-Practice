// Link: https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the input number.
// SC: O(1) for storing the result.
// Approach:
//       1. Initialize ans to 0 and bits to 0.
//       2. Iterate through the numbers from 1 to n.
//       3. For each number i, check if it is a power of 2. If it is, increment bits by 1.
//       4. Update ans by left-shifting it by bits and adding i, then take the modulo with 1e9 + 7
//       5. Return ans as the final result.
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bits = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
                bits++;

            ans = ((ans << bits) + i) % MOD;
        }
        return ans;
    }
};
