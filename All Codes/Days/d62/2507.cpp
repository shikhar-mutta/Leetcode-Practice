// Link: https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) per round, and the value strictly shrinks each round
//     until it reaches a fixed point (a prime), so this converges fast
// SC: O(1)
// Approach: repeatedly replace n with the sum of its prime factors (with
// multiplicity) via trial division up to sqrt(n). Once n equals its own
// prime-factor sum, n must itself be prime (a composite's prime-factor
// sum is always strictly smaller), so that's the fixed point to return.
class Solution {
public:
    int smallestValue(int n) {
        while (true) {
            int sum = primeFactorSum(n);
            if (sum == n)
                return n; // fixed point: n is prime
            n = sum;
        }
    }

private:
    int primeFactorSum(int n) {
        int sum = 0;
        for (int p = 2; (long long)p * p <= n; ++p) {
            while (n % p == 0) {
                sum += p;
                n /= p;
            }
        }
        if (n > 1)
            sum += n; // remaining prime factor
        return sum;
    }
};
