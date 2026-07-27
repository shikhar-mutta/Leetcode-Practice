// Link: https://leetcode.com/problems/largest-prime-from-consecutive-prime-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n) * n) worst-case-ish, in practice fast since sums grow
// quadratically SC: O(1)
// Approach: accumulate prefix sums of consecutive primes starting from
// 2 (2, 2+3, 2+3+5, ...); whenever a prefix sum itself is prime and does
// not exceed n, it's a candidate answer. Keep the largest such candidate
// while the running sum stays <= n.
class Solution {
    bool isPrime(long long x) {
        if (x < 2) return false;
        for (long long p = 2; p * p <= x; p++) if (x % p == 0) return false;
        return true;
    }
public:
    int largestPrime(int n) {
        int ans = -1;
        long long sum = 0;
        for (long long cand = 2; ; cand++) {
            if (!isPrime(cand)) continue;
            if (sum + cand > n) break;
            sum += cand;
            if (isPrime(sum)) ans = sum;
        }
        return ans;
    }
};
