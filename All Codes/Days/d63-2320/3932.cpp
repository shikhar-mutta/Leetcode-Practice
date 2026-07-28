// Link: https://leetcode.com/problems/count-k-th-roots-in-a-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(r)) SC: O(1)
// Approach: count integers n such that n^k lies within [l, r] — i.e.
// count perfect k-th powers in the range. Binary search for the largest
// n with n^k <= r, and the largest n with n^k < l, subtract.
class Solution {
    long long countUpTo(long long limit, int k) {
        // count of n>=1 with n^k <= limit
        if (limit < 1) return 0;
        long long lo = 1, hi = limit;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            __int128 p = 1;
            bool overflow = false;
            for (int i = 0; i < k; i++) {
                p *= mid;
                if (p > limit) { overflow = true; break; }
            }
            if (!overflow) lo = mid; else hi = mid - 1;
        }
        __int128 check = 1;
        for (int i = 0; i < k; i++) check *= lo;
        return (check <= limit) ? lo : 0;
    }
public:
    int countKthRoots(int l, int r, int k) {
        return (int)(countUpTo(r, k) - countUpTo(l - 1, k));
    }
};
