// Link: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(60)
// SC: O(1)
// Approach: after k operations, num1 becomes target = num1 - k*num2 (each op
// subtracts some power of 2, chosen 2^i for varying i, num2 fixed per op).
// Reaching exactly 0 in k ops is possible iff target can be written as a sum
// of exactly k powers of two, i.e. popcount(target) <= k <= target (need at
// least popcount(target) terms, but can always pad up to target terms by
// splitting a power of two into two smaller equal ones). Try k=1..60 and
// return the first feasible one; if num2 >= 0, target is non-increasing in k
// so once it drops below k it never recovers, allowing early exit to -1.
class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long target;
        for (int k = 1; k <= 60; ++k) {
            target = (long long)num1 - (long long)k * num2;
            if (target < k) {
                // if num2 >= 0, target only shrinks further; stop early
                if (num2 >= 0)
                    return -1;
                continue;
            }
            if (__builtin_popcountll(target) <= k)
                return k;
        }
        return -1;
    }
};
