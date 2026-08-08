// Link: https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log^2(k)) SC: O(1)
// Approach: trailing-zero count of n! is non-decreasing in n, and each achievable value is hit by exactly 5 consecutive n's. Binary search for the smallest n with zeroes(n) >= k; if zeroes(n) == k, the answer is 5, else 0.
class Solution {
    long long zeroes(long long n) {
        long long count = 0;
        for (long long p = 5; p <= n; p *= 5) count += n / p;
        return count;
    }
public:
    int preimageSizeFZF(int k) {
        long long lo = 0, hi = 5LL * (k+1);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (zeroes(mid) >= k) hi = mid;
            else lo = mid + 1;
        }
        return zeroes(lo) == k ? 5 : 0;
    }
};
