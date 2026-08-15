// Link: https://leetcode.com/problems/distinct-prime-factors-of-product-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int x : nums) {
            for (int p = 2; p * p <= x; p++) {
                while (x % p == 0) {
                    primes.insert(p);
                    x /= p;
                }
            }
            if (x > 1) primes.insert(x);
        }
        return primes.size();
    }
};
