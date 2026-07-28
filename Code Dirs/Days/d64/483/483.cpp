// Link: https://leetcode.com/problems/smallest-good-base/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(n)^2)  SC: O(1)
// Approach: n = 1 + k + k^2 + ... + k^(m-1) for base k with m digits.
// Try decreasing digit counts m from log2(n) down to 2 (base n-1 with
// m=2 always works), binary searching k for each m via the geometric
// series sum; the largest valid m gives the smallest base.
class Solution {
    long long geomSum(long long k, int m, long long limit) {
        // sum = 1 + k + ... + k^(m-1), capped early if it exceeds limit
        long long sum = 0, term = 1;
        for (int i = 0; i < m; i++) {
            sum += term;
            if (sum > limit) return sum;
            if (i < m - 1) {
                if (term > limit / k + 1) return limit + 1;
                term *= k;
            }
        }
        return sum;
    }
public:
    string smallestGoodBase(string ns) {
        long long n = stoll(ns);
        int maxM = 0;
        for (long long v = n; v > 1; v /= 2) maxM++; // upper bound on digit count

        for (int m = maxM; m >= 2; m--) {
            long long lo = 2, hi = (long long)pow((double)n, 1.0 / (m - 1)) + 2;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                long long s = geomSum(mid, m, n);
                if (s < n) lo = mid + 1;
                else hi = mid;
            }
            if (geomSum(lo, m, n) == n) return to_string(lo);
        }
        return to_string(n - 1);
    }
};
