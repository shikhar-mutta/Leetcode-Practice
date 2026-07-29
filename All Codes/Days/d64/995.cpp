// Link: https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(n)
// Approach: greedy left-to-right scan with a difference array tracking
// pending flips. Track the running flip parity via a difference array
// (increment at i, decrement at i+k); if the current effective value
// (original XOR parity-so-far) is 0, we must flip starting here — if
// the window doesn't fit (i+k>n), it's impossible.
class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        int ops = 0, f = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            // pop out
            if (i >= k)
                f -= nums[i - k];

            int curr = nums[i] + f;
            if (curr % 2 == 0)
            {
                ++f;
                nums[i] = 1;
            }
            else
            {
                nums[i] = 0;
            }
            ops += nums[i];
        }

        for (int i = n - 1; i > n - k; --i)
            if (nums[i] == 1)
                return -1;
        return ops;
    }
};
