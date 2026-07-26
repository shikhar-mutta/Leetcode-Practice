// Link: https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)
// SC: O(1)
// Approach: greedily process n bit by bit. A trailing 0 just shifts down
// (free, no operation). A trailing 1 costs one operation either way: an
// isolated 1 (next bit is 0) is cheapest to subtract off directly, while
// a run of 2+ trailing 1s is cheaper to clear by adding 1, which carries
// through the run and leaves a single higher bit set instead.
class Solution {
public:
    int minOperations(int n) {
        int ops = 0;
        while (n > 0) {
            if (n & 1) {
                // decide: subtract 1, or add 1 (to clear a run of 1s)
                if (n & 2) {
                    // run of 2+ ones: add 1 to carry, clearing the run into one higher bit
                    ++n;
                } else {
                    // isolated 1: subtract it
                    --n;
                }
                ++ops;
            } else {
                n >>= 1;   // trailing zero: shift down (equivalent to /2)
            }
        }
        return ops;
    }
};
