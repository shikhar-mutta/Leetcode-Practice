// Link: https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumPrimeFactors(int n) {
        int sum = 0;
        for (int p = 2; (long long)p * p <= n; p++) {
            while (n % p == 0) {
                sum += p;
                n /= p;
            }
        }
        if (n > 1) sum += n;
        return sum;
    }

    int smallestValue(int n) {
        while (true) {
            int next = sumPrimeFactors(n);
            if (next == n) return n;
            n = next;
        }
    }
};
