// Link: https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((hi-lo) * sqrt(hi)) SC: O(1)
// Approach: reverse the digits of n, take the inclusive range between n
// and its reverse, and sum all primes in that range via trial division.
class Solution {
    bool isPrime(int x) {
        if (x < 2) return false;
        for (int p = 2; (long long)p * p <= x; p++) if (x % p == 0) return false;
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int x = n, rev = 0;
        while (x > 0) { rev = rev * 10 + x % 10; x /= 10; }
        int lo = min(n, rev), hi = max(n, rev);

        int sum = 0;
        for (int v = lo; v <= hi; v++) if (isPrime(v)) sum += v;
        return sum;
    }
};
