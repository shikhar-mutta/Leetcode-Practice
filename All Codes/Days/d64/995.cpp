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
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int flips = 0, curFlips = 0;
        for (int i = 0; i < n; i++) {
            curFlips += diff[i];
            int effective = (nums[i] + curFlips) % 2;
            if (effective == 0) {
                if (i + k > n) return -1;
                flips++;
                curFlips++;
                diff[i + k]--;
            }
        }
        return flips;
    }
};
